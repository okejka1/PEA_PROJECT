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
    bool* visited;
    int pathLength;
    std::vector<int> currentPath;
    std::vector<int> bestPath;
    int *cheapestExit;

    void findCheapest(Graph &graph);
    int lowerBound(int vertex);

    void DFSApproach(int node, Graph &graph);


public:
    explicit BB(Graph &graph);
    ~BB();

    void print();


    int BBSolver(Graph &graph, int node);
};


#endif //PEA_BB_H
