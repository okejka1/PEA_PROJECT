#include "BB.h"


BB::BB(Graph &graph) {
    globalCost = INT_MAX;
    currentCost = 0;
    numOfCities = graph.vertices;
    visited = std::vector<bool>(numOfCities, false);
    findCheapest(graph);
}

BB::~BB() {

}

void BB::findCheapest(Graph &graph) {
    cheapestExit = std::vector<int>(numOfCities, INT_MAX);

    for (int i = 0; i < numOfCities; i++) {
        cheapestExit[i] = INT_MAX;
    }

    for (int i = 0; i < numOfCities; i++) {
        for (int j = 0; j < numOfCities; j++) {
            if (i != j && graph.edges[i][j] < cheapestExit[i])
                cheapestExit[i] = graph.edges[i][j];
        }
    }
}

int BB::lowerBound(int vertex) {
    int lowBound = 0;
    for (int i = 0; i < numOfCities; i++) {
        if (!visited[i] && i != vertex) {
            lowBound += cheapestExit[i];
        }
    }

    return lowBound;
}

int BB::BBSolver(Graph &graph, int start) {
    visited[start] = true;
    currentPath.push_back(start);
    DFSApproach(graph, start, 1, start);
//    std::cout << "last test\n";
    bestPath.push_back(start);

    return globalCost;


}

void BB::print() {
    for (auto city: bestPath) {
        std::cout << city << " ";
    }

}


void BB::DFSApproach(Graph &graph, int currentNode, int pathLength, int startingNode) {
    if (pathLength == numOfCities) {
        if (graph.edges[currentNode][startingNode] != INT_MAX) {
            if (currentCost + graph.edges[currentNode][startingNode] < globalCost) {
                globalCost = currentCost + graph.edges[currentNode][startingNode];
                bestPath = currentPath;
            }
        }
        return;
    } else {
        visited[currentNode] = true;
        for (int city = 0; city < numOfCities; city++) {
            if (currentCost + graph.edges[currentNode][city] + lowerBound(city) >= globalCost || visited[city])
                continue;
            currentCost += graph.edges[currentNode][city];
            currentPath.push_back(city);  // Add the current city to the path
            DFSApproach(graph, city, pathLength + 1, startingNode);
            currentPath.pop_back(); // Backtrack: Restore the state of currentPath
            currentCost -= graph.edges[currentNode][city];
        }
        visited[currentNode] = false;
    }
}
