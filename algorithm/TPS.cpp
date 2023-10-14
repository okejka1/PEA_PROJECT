//
// Created by User on 13.10.2023.
//

#include "TPS.h"
#include <vector>
#include <iostream>

//void TPS::bruteForce(Graph graph) {
//    int cost = 0;
//
//}

using namespace std;

int TPS::bruteForce(Graph& graph, vector<int>& path, vector<bool>& visited, int current, int n, int cost) {
    if (path.size() == n) {
        return cost + graph.edges[current][0];
    }

    int min_cost = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);

            int new_cost = bruteForce(graph, path, visited, i, n, cost + graph.edges[current][i]);

            min_cost = min(min_cost, new_cost);

            visited[i] = false;
            path.pop_back();
        }
    }

    return min_cost;
}