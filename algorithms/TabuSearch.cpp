
#include <random>
#include <iostream>
#include "Solution.h"
#include "TabuSearch.h"
#include "../utils/Timer.h"
#include "TabuSearch.h"
TabuList TabuSearch::tabulist(48);  // Define the static member variable

std::pair<Solution, long> TabuSearch::apply(Graph &graph, int maxDurationInSeconds, int neighbourMethod, int maxIterations) {
    tabulist.clear();
    Solution bestSolution = Solution::generateGreedySolution(graph);
    Solution currentSolution = bestSolution;

    long bestSolutionTime = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double random_number = dis(gen);
    Timer timer;
    timer.start();
    int iteration = 0;
    int iterationsSinceChange = 0;

    while(timer.mili() < maxDurationInSeconds * 1000 && iteration < maxIterations) {
        if (iterationsSinceChange >= maxIterations * 0.05) {
            std::cout << "Accept of worse neigbour solution due to being stuck in local optima\n";
            tabulist.clear();
            currentSolution = Solution::generateNeighbourSwap(graph, currentSolution, tabulist);

//            currentSolution = Solution::generateRandomSolution(graph);
            iterationsSinceChange = 0;

        }
        Solution neigbourSolution;
        switch(neighbourMethod){
            case 1:
                neigbourSolution = Solution::generateNeighbourSwap(graph, currentSolution, tabulist);
                break;
            case 2:
                neigbourSolution = Solution::generateNeighbour2Opt(graph, currentSolution, tabulist);
                break;
            case 3:
                if(random_number < 0.5) {
                    neigbourSolution = Solution::generateNeighbourSwap(graph, currentSolution, tabulist);
                } else
                    neigbourSolution = Solution::generateNeighbour2Opt(graph, currentSolution, tabulist);
                break;
            default:
                std::cout << "WRONG PAREAMETERS FOR DEFING NEIGHBOUR SOLUTION\n";
                break;
        }
        if(neigbourSolution.cost < currentSolution.cost) {
            iterationsSinceChange = 0;
            currentSolution = neigbourSolution;
            currentSolution.cost = Solution::calculateCost(graph, currentSolution);
            if(currentSolution.cost < bestSolution.cost) {
                iterationsSinceChange = 0;
                bestSolution = currentSolution;
                timer.stop();
                bestSolutionTime = timer.mili();
                bestSolution.cost = Solution::calculateCost(graph,bestSolution);
                Solution::print(bestSolution);
                std::cout << "\nbestSolution cost = " << bestSolution.cost << "\n";
                tabulist.push(bestSolution.move.first, bestSolution.move.second);
            }
        }
        timer.stop();
        iterationsSinceChange++;
        iteration++;
    }
    timer.stop();
    std::cout << "Final solution: ";
    Solution::print(bestSolution);
    std::cout << "\nFinal solution cost: " << bestSolution.cost << "\n";
    std::cout << "Final solution found in " << bestSolutionTime / 1000 << " seconds\n";
    return std::make_pair(bestSolution, bestSolutionTime);
}
