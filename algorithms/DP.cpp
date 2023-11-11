#include <vector>
#include <iostream>
#include "DP.h"
#include "../structures/Graph.h"

DP::DP() {


}

DP::~DP() {

}


int DP::DPSolver(Graph &graph) {
    int fullVisit = (1 << graph.vertices) - 1;
    int minCost = INT_MAX;
    int minCostPos = INT_MAX;
    int mostEfficientStartVertex = 0;
    std::vector<std::vector<int>> minParent;
    minParent.reserve(graph.vertices);

    for(int i = 0; i < graph.vertices; i++) {
        std::vector<std::vector<int>> dp(1 << graph.vertices, std::vector<int>(graph.vertices, -1));
        std::vector<std::vector<int>> parent(1 << graph.vertices, std::vector<int>(graph.vertices, -1));
        minCostPos = heldKarpAlg(1 << i, fullVisit, i, i,graph, dp, parent);
        if(minCostPos < minCost) {
            minCost = minCostPos;
            minParent = parent;
            mostEfficientStartVertex = i;
        }
    }

    backtrack(minParent, mostEfficientStartVertex);

    return minCost;
}

int DP::heldKarpAlg(int mask, int fullVisit, int currentPos, int startPos, Graph &graph,std::vector<std::vector<int>> &dp, std::vector<std::vector<int>> &parent) {
    if(mask == fullVisit)
        return graph.edges[currentPos][startPos];
    if(dp[mask][currentPos] != -1) {
        return dp[mask][currentPos];
    }
    int minLocal = INT_MAX;
    for(int i = 0; i < graph.vertices; i++) {
        if((mask & (1<< i)) == 0) {
            int newMinLocal = graph.edges[currentPos][i] + heldKarpAlg(mask | (1 << i), fullVisit, i, startPos, graph, dp, parent);
            if(newMinLocal < minLocal) {
                minLocal = newMinLocal;
                parent[mask][currentPos] = i;

            }
        }
    }
    return dp[mask][currentPos] = minLocal;

}

void DP::backtrack(std::vector<std::vector<int>> &parent, int start) {
        int curNode = start;
        int curMask = 1 << start;
        do {
            shortestPath.emplace_back(curNode);
            curNode = parent[curMask][curNode];
            curMask = curMask | (1<<curNode);
        } while(curNode != -1);
        shortestPath.emplace_back(start);
}

void DP::print() {
    for (auto city: shortestPath) {
        std::cout << city << " ";
    }

}
