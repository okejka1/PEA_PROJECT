#include <iostream>
#include "Menu.h"
#include "structures/Graph.h"
#include "algorithm/TPS.h"

using namespace std;

int main() {
    //Graph siema(403);
    //siema.readGraphDirected("rbg403.atsp", 403);
    //siema.display();
    Graph test(5);
    test.readGraphDirected("test.atsp", 5);
    //test.display();
    TPS t;
    vector<int> path;
    vector<bool> visited(5, false);

    int starting_city = 0;
    path.push_back(starting_city);
    visited[starting_city] = true;

    int min_cost = t.bruteForce(test, path, visited, starting_city, 5, 0);

    cout << "Minimum cost of TSP: " << min_cost << endl;
//    Menu::show();
    return 0;
}
