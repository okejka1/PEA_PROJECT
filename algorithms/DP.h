
#ifndef PEA_DP_H
#define PEA_DP_H


#include "../structures/Graph.h"

class DP {

private:
    std::vector<int> shortestPath;
    int heldKarpAlg(int mask, int fullVisit, int currentPos, int startPos, Graph &graph, std::vector<std::vector<int>> &dp,
                std::vector<std::vector<int>> &parent);

    void backtrack(std::vector<std::vector<int>> &parent, int start);

public:
    DP();
    ~DP();

    int ATSPdp(Graph &graph);

    void display();

};


#endif //PEA_DP_H
