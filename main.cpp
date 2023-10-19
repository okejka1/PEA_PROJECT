#include <iostream>
#include "structures/Graph.h"
#include "algorithm/BruteForce.h"
#include "testers/AutomaticTester.h"
#include "utils/FileRandomizer.h"
#include "utils/Timer.h"

using namespace std;

void waitForResponse();

int main() {
    int answer;
    do {
        cout << "What do you want to do?" << endl << "1. Manual test" << endl << "2. Automatic test" << endl;
        cin >> answer;
    }while(answer != 1 && answer != 2);

    if(answer == 1){
        int size = 5, choice;
        Graph graph(size);
        FileRandomizer::randomize(size);
        graph.readGraphDirected("random.atsp");
        do {

            Timer timer;

            cout    << "1. Generate random graph"   << endl
                    << "2. Load graph from file"    << endl
                    << "3. Test brute force"        << endl
                    << "4. Show graph"              << endl
                    << "5. Change size"             << endl
                    << "6. Exit program"            << endl;
            cin >> choice;
            switch(choice){
                case 1:{
                    FileRandomizer::randomize(size);
                    graph.readGraphDirected("random.atsp");
                    waitForResponse();
                    break;
                }
                case 2: {
                    string name;
                    cout << "Provide file name with extension: ";
                    cin >> name;
                    graph.readGraphDirected(name);
                    waitForResponse();
                    break;
                }
                case 3:{
                    BruteForce solver(graph);
                    int cost, start;
                    cout << "Provide the starting vertex: ";
                    cin >> start;
                    if(start < 0 || start >= size){
                        start = 0;
                        cout << "invalid starting vertex, starting vertex set to 0" << endl;
                    }

                    timer.start();
                    cost = solver.ATSPBruteForce(graph, start);
                    timer.stop();
                    solver.print();
                    cout    << "Cost of shortest hamiltonian cycle = " << cost << endl
                            << "Algorithm completed in " << timer.mili() << " miliseconds and " << timer.micro() << " microseconds" << endl;
                    waitForResponse();
                    break;
                }
                case 4:
                    graph.display();
                    break;
                case 5:{
                    cout << "What do you want the size to be? " << endl;
                    cin >> size;
                    while(size < 2 || size > 15){
                        cout << "Size must be a number between 2 and 15!" << endl;
                        cin >> size;
                    }
                    FileRandomizer::randomize(size);
                    graph.readGraphDirected("random.atsp");
                    waitForResponse();
                    break;
                }
                default:
                    break;
            }
        }while(choice != 6);
    }

    else
        AutomaticTester::testBruteForce();

    return 0;
}

void waitForResponse(){
    std::cout << "\n\npress ENTER to continue..." << std::endl;
    std::cin.ignore(10000, '\n');
    getchar();
}