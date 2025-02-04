#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>


class Graph {
public:
    // Создает новый регион с пустым множеством, если не создан
    void addRegion(const std::string& region) {
        regions_[region];
    }

    // Создает новое ребро между регионами
    void addEdge(const std::string& region1, const std::string& region2) {
        if (regions_.contains(region1) && regions_.contains(region2)) {
            if (region1 != region2) {
                regions_[region1].insert(region2);
                regions_[region2].insert(region1);
            }
        }
    }

    // Возвращает граф
    const std::unordered_map<std::string, std::unordered_set<std::string>>& getRegions() const {
        return regions_;
    }

    // Возвращает соседние к заданному региону регионы
    const std::unordered_set<std::string>& getNeighbours(const std::string& region) const {
        return regions_.at(region);
    }

    // Проверяет граф на наличие петель и дублирующих ребер
    bool validate() const {
        for (const auto& [region, neighbours] : regions_) {
            if (neighbours.contains(region)) {
                return false;
            }
            for (const auto& neighbour : neighbours) {
                if (regions_.at(neighbour).contains(region)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Возвращает количество регионов
    size_t size() const {
        return regions_.size();
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> regions_ = {};
};