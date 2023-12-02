#include <iostream>
#include "structures/Graph.h"
#include "algorithms/BruteForce.h"
#include "testers/AutomaticTester.h"
#include "utils/FileRandomizer.h"
#include "utils/Timer.h"
#include "algorithms/DP.h"
#include "algorithms/BB.h"
#include <string>



//void waitForResponse() {
//    std::cout << std::endl << std::endl << "press ENTER to continue..." << std::endl;
//    std::cin.ignore(10000, '\n');
//    getchar();
//}


void menu() {
    int option = -1;
    std::string fileName;
    Graph graph(1);
    std::cout << "\nAlgorithms and computational complexity\n";
    do {
        std::cout << endl;
        std::cout << "1. Load graph from file\n";
        std::cout << "2. Generate random graph\n";
        std::cout << "3. Show graph (adjacency matrix)\n";
        std::cout << "4. Test brute force\n";
        std::cout << "5. Test DP\n";
        std::cout << "6. Test B&B\n";
        std::cout << "7. Test tabu search\n";
        std::cout << "8. Time measurements for BF approach\n";
        std::cout << "9. Time measurements for DP approach\n";
        std::cout << "10. Time measurements for B&B approach\n";
        std::cout << "11. Exit\n";
        std::cout << "Choose an option:";

        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Provide filename:";
                std::cin >> fileName;
                graph.readGraphDirected(fileName);
                break;
            case 2: {
                int size = 0;
                std::cout << "Provide size:";
                std::cin >> size;
                fileName = "random.atsp";
                FileRandomizer::randomize(size);
                graph.readGraphDirected(fileName);
                break;
            }
            case 3:
                graph.display();
                break;
            case 4: {
                Timer timer;
                int cost;
                int start;
                BruteForce solver(graph);
                std::cout << "Provide the starting vertex:";
                std::cin >> start;
                if (start < 0 || start >= graph.vertices) {
                    start = 0;
                    std::cout << "invalid starting vertex, starting vertex set to 0" << endl;
                }
                timer.start();
                cost = solver.ATSPBruteForce(graph, start);
                timer.stop();
                solver.print();
                std::cout << "Cost of shortest hamiltonian cycle = " << cost << endl
                          << "Algorithm completed in " << timer.mili() << " miliseconds and " << timer.micro()
                          << " microseconds" << endl;
                break;
            }
            case 5: {
                Timer timer;
                int cost = 0;
                DP solver;
                timer.start();
                cost = solver.DPSolver(graph);
                timer.stop();
                solver.print();
                std::cout << "Cost of shortest hamiltonian cycle = " << cost << endl
                          << "Algorithm completed in " << timer.mili() << " miliseconds and " << timer.micro()
                          << " microseconds" << endl;
                break;
            }
            case 6: {
                Timer timer;
                int cost = 0;
                int start;
                std::cout << "Provide the starting vertex:";
                std::cin >> start;
                if (start < 0 || start >= graph.vertices) {
                    start = 0;
                    std::cout << "invalid starting vertex, starting vertex set to 0" << endl;
                }
                BB solver(graph);
                timer.start();
                cost = solver.BBSolver(graph, start);
                timer.stop();
                solver.print();
                std::cout << "Cost of shortest hamiltonian cycle = " << cost << endl
                          << "Algorithm completed in " << timer.mili() << " miliseconds and " << timer.micro()
                          << " microseconds" << endl;
                break;
            }
            case 7:
                break;
            case 8:
                AutomaticTester::testBruteForce();
                break;
            case 9:
                AutomaticTester::testDynamicProgramming();
                break;
            case 10:
                AutomaticTester::testBranchAndBound();
                break;
            case 11:
                break;
            default:
                std::cout << "Invalid input,try again\n";
        }
    } while (option != 11);
};

int main() {
    menu();


    return 0;
}

