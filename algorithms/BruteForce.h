//
// Created by User on 13.10.2023.
//

#ifndef PEA_BRUTEFORCE_H
#define PEA_BRUTEFORCE_H

#include "vector"
#include "../structures/Graph.h"

using namespace std;

class BruteForce {
private:
    int globalCost;
    bool* visited;
    int currentCost;
    vector<int> currentPath;
    vector<int> bestPath;
    void bruteForce(Graph& graph, int current, int n, int start);
public:
    explicit BruteForce(const Graph& graph);

    virtual ~BruteForce();

    int ATSPBruteForce(Graph& graph, int start);
    void print();
};


#endif //PEA_BRUTEFORCE_H
