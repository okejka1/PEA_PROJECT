#include <iostream>
#include "structures/Graph.h"
//#include "algorithms/BruteForce.h"
//#include "testers/AutomaticTester.h"
//#include "utils/FileRandomizer.h"
//#include "utils/Timer.h"
//#include "algorithms/DP.h"
//#include "algorithms/BB.h"
#include <string>



//void waitForResponse() {
//    std::cout << std::endl << std::endl << "press ENTER to continue..." << std::endl;
//    std::cin.ignore(10000, '\n');
//    getchar();
//}

/*
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
*/
#include <iostream>
#include <string>
#include <fstream>
#include "structures/Graph.h"
#include "algorithms/TabuSearch.h"
#include "utils/Timer.h"


using namespace std;

void test() {
    Graph graph(1);
    string fileName;
    int fileOption;

    cout << "Choose a file that you want to conduct a test on\n";
    cout << "1. ftv47.atsp\n";
    cout << "2. ftv170.atsp\n";
    cout << "3. rbg403.atsp\n";

    cin >> fileOption;
    cin.clear();
    cin.ignore();

    switch (fileOption) {
        case 1:
            fileName = "ftv47.atsp";
            break;
        case 2:
            fileName = "ftv170.atsp";
            break;
        case 3:
            fileName = "rbg403.atsp";
            break;
        default:
            cout << "Invalid input\n\n";
            return;
    }

    graph.readGraphDirected(fileName);
    Timer timer;
    long long sekundy = 5000;

    long long elapsedTime = 0;
    timer.start();

    while (elapsedTime < sekundy) {
        elapsedTime = timer.mili();
        cout << "Aktualny czas: " << elapsedTime << " ms" << endl;
        timer.stop();  // Move timer.stop() inside the loop
    }




}
void run() {
    cout << "\nTABU SEARCH -- ATSP\n";
    int option;

    int optimalCost;
    // initial options
    string fileName = "rbg403.atsp";
    int neighbourhoodMethod = 3;
    int endConditionInSeconds = 120;
    Graph graph(1);  // Create a new graph object
    graph.readGraphDirected(fileName);


    do {

        cout << "1.Load graph from file\n";
        cout << "2.Change stop condition\n";
        cout << "3.Chose neighbourhood\n";
        cout << "4.Tabu search\n";
        cout << "5.Automatic tester\n";
        cout << "6.Exit\n";
        cout << "Choose an option:";


        cin >> option;
        cin.clear(); //This corrects the stream.
        cin.ignore(); //This skips the left over stream data.


        switch (option) {
            case 1: {

                do {

                    cout << "Choose a file that you want to conduct test on\n";
                    cout << "1.ftv47.atsp\n";
                    cout << "2.ftv170.atsp\n";
                    cout << "3.rbg403.atsp\n";
                    cin >> option;
                    cin.clear();
                    cin.ignore();

                } while (option < 1 || option > 3);

                if (option == 1) {
                    fileName = "ftv47.atsp";
                    optimalCost = 1776;
                }
                if (option == 2) {
                    fileName = "ftv170.atsp";
                    optimalCost = 2755;
                }
                if (option == 3) {
                    fileName = "rbg403.atsp";
                    optimalCost = 2465;
                }
                graph.readGraphDirected(fileName);
                break;
            }
            case 2:
                cout << "Enter your stop criteria (time in seconds):\n";
                cin >> endConditionInSeconds;
                cin.clear();
                cin.ignore();
                break;
            case 3:
                cout << "Choose your method to define neighbours\n";
                cout << "1.Swap two Cities\n";
                cout << "2.2-opt method\n";
                cout << "3.Hybrid of previous two methods\n";
                cin >> neighbourhoodMethod;
                cin.clear();
                cin.ignore();
                break;

            case 4: {
                TabuSearch::apply(graph, endConditionInSeconds, neighbourhoodMethod, 200000000);
                break;
            }
            case 5: { // AUTO TESTS;
                cout << "Choose your method to define neighbours that you want to conduct test on\n";
                cout << "1.Swap two Cities\n";
                cout << "2.2-opt method\n";
                cout << "3.Hybrid of previous two methods\n";
                cin >> neighbourhoodMethod;
                cin.clear();
                cin.ignore();
                ofstream file((R"(..\output\results_)" + fileName + "_" + to_string(neighbourhoodMethod) + ".csv"));
                if (file.is_open()) {
                    if (fileName == "ftv47.atsp") {
                        endConditionInSeconds = 120;
                        optimalCost = 1776;
                    } else if (fileName == "ftv170.atsp") {
                        endConditionInSeconds = 240;
                        optimalCost = 2755;
                    } else if (fileName == "rbg403.atsp") {
                        endConditionInSeconds = 360;
                        optimalCost = 2465;
                    }
                    file << "cost;" << "time;" << "% error;" << optimalCost << "\n";

                    Solution testSolution;
                    testSolution.cost = INT_MAX;
                    int numOfTests = 10;
                    for (int i = 0; i < numOfTests; i++) {
                        pair<Solution, long> resultOfTest = TabuSearch::apply(graph, endConditionInSeconds,
                                                                              neighbourhoodMethod, 200000000);
                        int actualCost = resultOfTest.first.cost;
                        int percentageError = static_cast<int>(((actualCost - optimalCost) * 100.0) / optimalCost);

                        file << actualCost << ";" << resultOfTest.second << ";" << percentageError << "%" << ";"
                             << optimalCost << endl;
                        if (resultOfTest.first.cost < testSolution.cost) {
                            testSolution = resultOfTest.first;
                        }
                    }
                    file << "path of best solution" << endl;
                    for (int item: testSolution.path)
                        file << item <<"->";
                    file << testSolution.path[0] << endl;
                    file.close();
                }
                break;
            }
            case 6:
                break;
            default:
                cout << "Invalid input\n\n";
                break;

        }

    }while(option != 6);

}
int main() {
   run();
   //test();

    return 0;
}



