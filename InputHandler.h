#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Graph.h"


/*В первой строке перечисляются все регионы через пробел. 
В каждой следующей строке перечисляются связь каждого из регионов с другими:
A B C D
B C
A D
A D
B C*/
class InputHandler {
public:
    // Читаем входные данные из файла
    static inline Graph readFromFile(const std::string& filename) {
        Graph graph;

        std::ifstream file(filename);
        if (!file) {
            throw "No input file with this name";
        }

        // Читаем все регионы
        std::string line;
        if (std::getline(file, line)) {
            std::istringstream str_stream(line);
            std::string region;
            while (str_stream >> region) {
                graph.addRegion(region);
            }
        }

        // Читаем связи регионов между собой
        while (std::getline(file, line)) {
            std::istringstream str_stream(line);
            std::string region1, region2;
            str_stream >> region1 >> region2;
            graph.addEdge(region1, region2);
        }

        file.close();
        return graph;
    }

    // Читаем входные данные из консоли
    static inline Graph readFromConsole() {
        Graph graph;

        // Читаем все регионы
        std::string line;
        if (std::getline(std::cin, line)) {
            std::istringstream str_stream(line);
            std::string region;
            while (str_stream >> region) {
                graph.addRegion(region);
            }
        }

        // Читаем связи регионов между собой
        while (std::getline(std::cin, line)) {
            std::istringstream str_stream(line);
            std::string region1, region2;
            str_stream >> region1 >> region2;
            graph.addEdge(region1, region2);
        }

        return graph;
    }
};