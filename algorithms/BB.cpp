#include "BB.h"


BB::BB(Graph &graph) {
    globalCost = INT_MAX;
    currentCost = 0;
    numOfCities = graph.vertices;
    visited = new bool[numOfCities];


    for(int i = 0; i < numOfCities; i++) {
        visited[i] = false;
    }
    findCheapest(graph);

}

BB::~BB() {
    delete[] visited;

}

void BB::findCheapest(Graph &graph) {

    cheapestExit = new int[numOfCities];

    for(int i = 0; i < numOfCities; i++) {
        cheapestExit[i] = INT_MAX;
    }

    for(int i = 0; i < numOfCities; i++) {
        for(int j = 0; j < numOfCities; j++) {
            if(i != j && graph.edges[i][j] < cheapestExit[i])
                cheapestExit[i] = graph.edges[i][j];
        }
    }

}

int BB::lowerBound(int vertex) {
    int lowBound = 0;
    for(int i = 0; i < numOfCities; i++) {
        if(!visited[i] && i != vertex) {
            lowBound += cheapestExit[i];
        }

    }
    return lowBound;
}

int BB::BBSolver(Graph &graph, int node) {

    return 0;
}

void BB::print() {

}


