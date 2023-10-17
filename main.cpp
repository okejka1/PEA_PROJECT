#include <iostream>
#include "structures/Graph.h"
#include "algorithm/BruteForce.h"
#include "testers/AutomaticTester.h"
#include "utils/FileRandomizer.h"

using namespace std;

int main() {
    int answer;
    do {
        cout << "What do you want to do?" << endl << "1. Manual test" << endl << "2. Automatic test" << endl;
        cin >> answer;
    }while(answer != 1 && answer != 2);

    if(answer == 1){
        int size;
        do {
            cout << "What size do you want your graph to be?" << endl;
            cin >> size;
        }while(size < 2);
        Graph graph(size);

        do {
            cout << "Do you want to\n1. load graph from file\n2. randomize" << endl;
            cin >> answer;
        }while(answer != 1 && answer != 2);

        if(answer == 1){

        }

        else{
            FileRandomizer::randomize(size);
        }

    }

    else {
        AutomaticTester tester;
        tester.testBruteForce();
    }
    return 0;
}
