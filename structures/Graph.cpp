//
// Created by User on 13.10.2023.
//

#include <vector>
#include "Graph.h"
#include "fstream"
#include "iostream"
#include "iomanip"

Graph::Graph(int v){
    vertices = v;
    edges = new int * [vertices];
    for(int i = 0; i < vertices; ++i) edges[i] = new int[vertices];

    for(int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            edges[i][j] = INT_MAX;
        }
    }
}

Graph::~Graph() {
    if(vertices > 0) {
        for (int i = 0; i < vertices; i++) {
            delete[] edges[i];
            edges[i] = nullptr;
        }
        delete[] edges;
        edges = nullptr;
    }
}

void Graph::readGraphDirected(std::string s) const {
    std::string name = R"(C:\Users\antek\Desktop\studia\5.sem\PEA_PROJECT\input\)" + s;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::vector<int> lineData;

        std::getline(file, line);

        int i = 0;
        while(std::getline(file, line)){
            std::stringstream lineStream(line);
            int value;
            while (lineStream >> value)
                lineData.push_back(value);
            if(lineData.size() == vertices){
                std::copy(lineData.begin(), lineData.end(), edges[i]);
                i++;
                lineData.clear();
            }

        }

        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE";
}

void Graph::display() const{

    const int fieldWidth = 4;
    std::cout << "Graph as matrix" << std::endl;

    std::cout << std::setw(fieldWidth) << " " << " | ";
    for (int j = 0; j < vertices; j++) {
        std::cout << std::setw(fieldWidth) << j << " ";
    }
    std::cout << std::endl;

    std::cout << std::setfill('-') << std::setw(fieldWidth + 1) << "" << "+" << std::setw((fieldWidth + 1) * vertices) << "" << std::setfill(' ') << std::endl;

    for (int i = 0; i < vertices; i++) {
        std::cout << std::setw(fieldWidth) << i << " | ";
        for (int j = 0; j < vertices; j++) {
            if(edges[i][j] == INT_MAX )
                std::cout << std::setw(fieldWidth) << "-" << " ";
            else
                std::cout << std::setw(fieldWidth) << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
