#pragma once

#include <fstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Graph.h"
#include "OutputHandler.h"


class ColoringAlgorithm {
public:
    ColoringAlgorithm(const Graph& graph) : graph_(graph) {}

    // Составлякт порядок раскраски регионов и запускает раскрасу методом перебора с возвратом
    void run() {
        std::vector<std::string> regions_order;

        // Выбирается случайный регион, потом добавляются его соседи, дальше соседи соседей и так далее
        // Рассматриваются все компоненты смежности
        std::unordered_map<std::string, bool> visited;
        for (const auto& [region, neighbours] : graph_.getRegions()) {
            if (!visited[region]) {
                regions_order.push_back(region);
                colored_regions_[region] = 0;
                visited[region] = true;

                std::stack<std::string> order;
                for (const std::string& neighbour : neighbours) {
                    if (!visited[neighbour]) {
                        order.push(neighbour);
                    }
                }

                while (!order.empty()) {
                    std::string next_region = order.top();
                    colored_regions_[next_region] = 0;
                    visited[next_region] = true;
                    order.pop(); 
                    regions_order.push_back(next_region);
                    for (const std::string& neighbour : graph_.getNeighbours(next_region)) {
                        if (!visited[neighbour]) {
                            order.push(neighbour);
                        }
                    }  
                }
            }
        }

        // Очищаем файл логов
        std::ofstream file("log.txt");
        file.close();

        // Запускаем алгоритм раскрашивания
        backtrack(regions_order, 0);
    }

    // Возвращает минимальное число необходимых красок
    int getMinColors() const {
        return colors_;
    }

    // Возвращает регионы раскрашенные в цвета
    const std::unordered_map<std::string, int>& getColorAssignment() const {
        return colored_regions_;
    }

private:
    Graph graph_;
    int colors_ = 0;
    std::unordered_map<std::string, int> colored_regions_ = {};

    // Проверяет, можно ли безопасно раскрасить заданный регион в определенный цвет
    bool isSafe(const std::string& region, int color) {
        for (const std::string& neighbour : graph_.getNeighbours(region)) {
            if (colored_regions_[neighbour] == color) {
                return false;
            }
        }

        return true;
    }

    // Раскрашивание регионов методом перебора с возвратом
    bool backtrack(const std::vector<std::string>& regions_order, size_t index) {
        // Условие окончания раскрашивания регионов
        if (index == regions_order.size()) {
            return true;
        }

        // Проверка возможности безопасного раскрашивания данного региона в определнный цвет
        for (int color = 1; color <= colors_; ++color) {
            if (isSafe(regions_order[index], color)) {
                colored_regions_[regions_order[index]] = color;
                OutputHandler::writeToFile("log.txt", getColorAssignment(), getMinColors());

                // Делаем то же самое для следующего региона
                if (backtrack(regions_order, index + 1)) {
                    return true;
                }

                // Если не получилось, то убираем цвет с данного региона и пробуем другой
                colored_regions_[regions_order[index]] = 0;
                OutputHandler::writeToFile("log.txt", getColorAssignment(), getMinColors());
            }
        }

        // Если мы вернулись в начальный регион, то добавляем новый цвет
        while (index == 0) {
            ++colors_;
            colored_regions_[regions_order[0]] = colors_;
            if (backtrack(regions_order, index + 1)) {
                return true;
            }
        }

        return false;
    }
};