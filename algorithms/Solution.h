//
// Created by User on 17.12.2023.
//

#ifndef PEA_SOLUTION_H
#define PEA_SOLUTION_H


#include "../structures/Graph.h"
#include <vector>
#include "iostream"
#include "../structures/TabuList.h"

using namespace std;

class Solution {
public:
    int cost = 0;
    vector <int> path;
    pair<int, int> move;

    static Solution generateRandomSolution(Graph &graph);
    static int calculateCost(Graph &graph, Solution solution);
    static int findNearestCity(const Graph& graph, int currentCity, const std::vector<bool>& visited);
    static void print(Solution solution);
    // static Solution generateNeighbourSwap(Graph &graph, Solution &currentSolution);
    static Solution generateNeighbour2Opt(Graph &graph, Solution currentSolution, TabuList &tabuList);
    static Solution generateGreedySolution(Graph &graph);

    static Solution generateNeighbourSwap(Graph &graph, Solution currentSolution, TabuList &tabuList);


};


#endif //PEA_SOLUTION_H
