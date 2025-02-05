#pragma once

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "ColoringAlgorithm.h"
#include "Graph.h"

class Test {
public:
    static inline void Test1() {
        Graph graph;

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 0);
        std::cerr << "TEST1 -> OK" << std::endl;
    }

    static inline void Test2() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C", "D", "E"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }
        for (size_t i = 0; i < regions.size(); ++i) {
            for (size_t j = i; j < regions.size(); ++j) {
                graph.addEdge(regions[i], regions[j]);
            }
        }

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 5);

        std::cerr << "TEST2 -> OK" << std::endl;
    }

    static inline void Test3() {
        Graph graph;
        std::vector<std::string> regions = {"A"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 1);

        std::cerr << "TEST3 -> OK" << std::endl;
    }

    static inline void Test4() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 1);

        std::cerr << "TEST4 -> OK" << std::endl;
    }

    static inline void Test5() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }
        graph.addEdge("A", "B");
        graph.addEdge("B", "c");

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 2);

        std::cerr << "TEST5 -> OK" << std::endl;
    }

    static inline void Test6() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }
        graph.addEdge("A", "B");

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 2);

        std::cerr << "TEST6 -> OK" << std::endl;
    }

    static inline void Test7() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C", "D"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }
        graph.addEdge("A", "B");
        graph.addEdge("B", "C");
        graph.addEdge("C", "D");

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 2);

        std::cerr << "TEST7 -> OK" << std::endl;
    }

    static inline void Test8() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }
        graph.addEdge("A", "B");
        graph.addEdge("A", "C");

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 2);

        std::cerr << "TEST8 -> OK" << std::endl;
    }

    static inline void Test9() {
        Graph graph;
        std::vector<std::string> regions = {"A", "B", "C"};
        for (const std::string& region : regions) {
            graph.addRegion(region);
        }
        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("B", "C");

        ColoringAlgorithm solver(graph);
        solver.run();

        assert(solver.getMinColors() == 3);

        std::cerr << "TEST9 -> OK" << std::endl;
    }
};