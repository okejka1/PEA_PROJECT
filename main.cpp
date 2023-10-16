#include <iostream>
#include "Menu.h"
#include "structures/Graph.h"
#include "algorithm/BruteForce.h"

using namespace std;

int main() {

    Graph test(4);
    test.readGraphDirected("test2.atsp", 4);
    test.display();
    BruteForce t(test);

    int starting_city = 0;
    //path.push_back(starting_city);

    int min_cost = t.ATSPBruteForce(test, starting_city);

    cout << "Minimum cost of TSP: " << min_cost << endl;
    t.print();
//    Menu::show();
    return 0;
}
