// Solution.cpp
#include "Solution.h"
#include <random>
#include <iostream>
#include <algorithm>

Solution Solution::generateGreedySolution(Graph &graph) {
    Solution solution;
    int numberOfCities = graph.vertices;
    std::vector<bool> visited(numberOfCities, false);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomCity(0, numberOfCities - 1);
    int currentCity = randomCity(gen);

    solution.path.push_back(currentCity);
    visited[currentCity] = true;
    for (int i = 1; i < numberOfCities; ++i) {
        int nearestCity = findNearestCity(graph, currentCity, visited);
        solution.path.push_back(nearestCity);
        visited[nearestCity] = true;
        solution.cost += graph.edges[currentCity][nearestCity];
        currentCity = nearestCity;
    }
    solution.cost += graph.edges[currentCity][solution.path[0]];
    return solution;
}

Solution Solution::generateRandomSolution(Graph &graph) {
    Solution solution;
    int numberOfCities = graph.vertices;
    std::vector<int> indices(numberOfCities);
    std::iota(indices.begin(), indices.end(), 0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(indices.begin(), indices.end(), gen);

    solution.path = indices;

    // Calculate the cost of the random solution
    solution.cost = calculateCost(graph, solution);
    return solution;
}

Solution Solution::generateNeighbourSwap(Graph& graph, Solution currentSolution, TabuList& tabuList) {
    Solution neighbourSolution = currentSolution;
    int numberOfCities = static_cast<int>(currentSolution.path.size());
    int city1, city2;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomVertex(0, numberOfCities - 1);
    do {
        city1 = randomVertex(gen);
        city2 = randomVertex(gen);
    } while (city1 == city2 || tabuList.findMove(city1, city2));

    if (city1 > city2) {
        std::swap(city1, city2);
    }
    Solution newSolution = currentSolution;
    newSolution.path = currentSolution.path;
    std::swap(newSolution.path[city1], newSolution.path[city2]);
    // Check if the move is already in the tabuList
    if (!tabuList.findMove(city1, city2)) {
        int newCost = Solution::calculateCost(graph, newSolution);
        neighbourSolution.path = newSolution.path;
        neighbourSolution.cost = newCost;
        neighbourSolution.move = {city1, city2};
    }
    return neighbourSolution;
}



int Solution::calculateCost(Graph &graph, Solution solution) {
    int cost = 0;
    int numberOfCities = graph.vertices;

    for (int i = 0; i < numberOfCities - 1; ++i) {
        cost += graph.edges[solution.path[i]][solution.path[i + 1]];
    }

    cost += graph.edges[solution.path[numberOfCities - 1]][solution.path[0]];

    return cost;
}
void Solution::print(Solution solution) {
    std::cout << "Path: ";
    for (int city : solution.path) {
        std::cout << city << " -> ";
    }
    std::cout << solution.path[0] << "\n";
    std::cout << "Cost: " << solution.cost << "\n";
}

int Solution::findNearestCity(const Graph &graph, int currentCity, const std::vector<bool> &visited) {
    int numberOfCities = graph.vertices;
    int nearestCity = -1;
    int minDistance = INT_MAX;

    for (int j = 0; j < numberOfCities; ++j) {
        if (!visited[j] && graph.edges[currentCity][j] < minDistance) {
            nearestCity = j;
            minDistance = graph.edges[currentCity][j];
        }
    }

    return nearestCity;
}



Solution Solution::generateNeighbour2Opt(Graph& graph, Solution currentSolution, TabuList& tabuList) {
    Solution neighbourSolution = currentSolution;
    int numberOfCities = static_cast<int>(currentSolution.path.size());

    int city1, city2, city3, city4;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomVertex(0, numberOfCities - 1);

    do {
        city1 = randomVertex(gen);
        city2 = randomVertex(gen);
        city3 = randomVertex(gen);
        city4 = randomVertex(gen);
    } while (city1 == city2 || city3 == city4 || tabuList.findMove(city1, city2) || tabuList.findMove(city3, city4));

    // Check if the move is already in the tabuList
    if (!tabuList.findMove(city1, city2) && !tabuList.findMove(city3, city4)) {
        std::swap(neighbourSolution.path[city1], neighbourSolution.path[city2]);
        std::swap(neighbourSolution.path[city3], neighbourSolution.path[city4]);
        int newCost = calculateCost(graph, neighbourSolution);
        neighbourSolution.cost = newCost;
        neighbourSolution.move = {city1, city2};
    }
    return neighbourSolution;

}
