#include <iostream>
#include <vector>
#include "../structures/Graph.h"


#ifndef PEA_BB_H
#define PEA_BB_H


class BB {

private:
    int globalCost;
    int currentCost;
    int numOfCities;
    std::vector<bool> visited;
    std::vector<int> currentPath;
    std::vector<int> bestPath;
    std::vector<int> cheapestExit;

    void findCheapest(Graph &graph);

    int lowerBound(int vertex);

    void DFSApproach(Graph &graph, int currentNode, int pathLength, int startingNode);


public:
    explicit BB(Graph &graph);

    ~BB();

    void print();

    int BBSolver(Graph &graph, int start);

};


#endif //PEA_BB_H