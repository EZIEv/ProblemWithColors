#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>


/*Поочередно в каждой строке выводится название региона и его цвет.
В последней строке выводится количество использованных цветов*/
class OutputHandler {
public:
    // Вывод раскрашенных регионов и количество использованных цветов в консоль
    static inline void printToConsole(const std::unordered_map<std::string, int>& colorAssignment, int colors) {
        for (const auto& [region, color] : colorAssignment) {
            std::cout << "Region " << region << ": Color " << color << "\n"; 
        }
        std::cout << "Used colors: " << colors << "\n";
        std::cout << std::endl;
    }

    // Вывод раскрашенных регионов и количество использованных цветов в файл
    static inline void writeToFile(const std::string& filename, const std::unordered_map<std::string, int>& colorAssignment, int colors) {
        std::ofstream file(filename, std::ios::app);
        for (const auto& [region, color] : colorAssignment) {
            file << "Region " << region << ": Color " << color << "\n"; 
        }
        file << "Used colors: " << colors << "\n";
        file << std::endl;
        file.close();
    }
};