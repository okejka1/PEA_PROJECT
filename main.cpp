#include <iostream>
#include "structures/Graph.h"
#include "algorithms/BruteForce.h"
#include "testers/AutomaticTester.h"
#include "utils/FileRandomizer.h"
#include "utils/Timer.h"
#include "algorithms/DP.h"
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
        std::cout << "7. Time measurements for BF approach\n";
        std::cout << "8. Time measurements for DP approach\n";
        std::cout << "9. Time measurements for B&B approach\n";
        std::cout << "10. Exit\n";
        std::cout << "Choose an option:";

        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Provide filename:";
                std::cin >> fileName;
                graph.readGraphDirected(fileName);
//                waitForResponse();
//                system("CLS");
                break;
            case 2: {
                int size = 0;
                std::cout << "Provide size:";
                std::cin >> size;
                fileName = "random.atsp";
                FileRandomizer::randomize(size);
                graph.readGraphDirected(fileName);
//                waitForResponse();
//                system("CLS");
                break;
            }
            case 3:
                graph.display();
//                waitForResponse();
//                system("CLS");
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
//                waitForResponse();
//                system("CLS");
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
            case 6:

                break;
            case 7:
                AutomaticTester::testBruteForce();
                break;
            case 8:
                AutomaticTester::testDynamicProgramming();
                break;
            case 9:
                break;
            case 10:
                break;
            default:
                std::cout << "Invalid input,try again\n";
        }
    } while (option != 10);
}



int main() {
   menu();


    return 0;
}

