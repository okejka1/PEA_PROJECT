//
// Created by User on 13.10.2023.
//

#include "BruteForce.h"
#include <vector>
#include <iostream>


using namespace std;

BruteForce::BruteForce(const Graph& graph){
    globalCost = INT_MAX;
    currentCost = 0;
    visited = new bool[graph.vertices];

    for(int i = 0; i < graph.vertices; i++){
        visited[i] = false;
    }
}

int BruteForce::ATSPBruteForce(Graph &graph, int start) {

    //create vector containing information about which vertices have been visited
    visited[start] = true;
    currentPath.push_back(start);

    bruteForce(graph, start, 1, start);

    bestPath.push_back(start);  // to complete the cycle
    return globalCost;
}

void BruteForce::bruteForce(Graph& graph, int current, int n, int start) {

    //if we reached the last vertex in the path
    if (n == graph.vertices) {
        if (graph.edges[current][start] != INT_MAX) {
            if (currentCost + graph.edges[current][start] < globalCost) { // ???
                globalCost = currentCost + graph.edges[current][start];
                bestPath = currentPath;
            }
        }
        return;
    }

    for (int i = 0; i < graph.vertices; i++) {
        if (!visited[i] && graph.edges[current][i] != INT_MAX) {
            visited[i] = true;
            currentPath.push_back(i);
            currentCost += graph.edges[current][i];

            bruteForce(graph, i,  n + 1, start);


            visited[i] = false; // backtrack
            currentPath.pop_back();
            currentCost -= graph.edges[current][i];
        }
    }
}

void BruteForce::print() {
    for(auto element : bestPath){
        cout << element << " ";
    }
}

BruteForce::~BruteForce() {
    delete[] visited;
}
