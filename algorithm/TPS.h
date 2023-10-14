//
// Created by User on 13.10.2023.
//

#ifndef PEA_TPS_H
#define PEA_TPS_H

#include "vector"
#include "../structures/Graph.h"

using namespace std;

class TPS {
public:
    int bruteForce(Graph &graph, vector<int>& path, vector<bool>& visited, int current, int n, int cost);
};


#endif //PEA_TPS_H
