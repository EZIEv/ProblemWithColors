#include "ColoringAlgorithm.h"
#include "Graph.h"
#include "InputHandler.h"
#include "OutputHandler.h"
#include "Test.h"

void Tests() {
    Test::Test1();
    Test::Test2();
    Test::Test3();
    Test::Test4();
    Test::Test5();
    Test::Test6();
    Test::Test7();
    Test::Test8();
    Test::Test9();
}

int main() {
    Tests();

    try {
        Graph graph = InputHandler::readFromFile("input.txt");
        ColoringAlgorithm solver(graph);
        solver.run();
        OutputHandler::printToConsole(solver.getColorAssignment(), solver.getMinColors());
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}