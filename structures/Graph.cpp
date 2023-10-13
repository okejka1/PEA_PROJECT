//
// Created by User on 13.10.2023.
//

#include <vector>
#include "Graph.h"
#include "sstream"
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

void Graph::readGraphDirected(std::string s, int size) {
    std::string name = R"(C:\Users\User\CLionProjects\PEA\input\)" + s;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::vector<int> lineData;
        int i = 0;
        while(std::getline(file, line)){
            std::stringstream lineStream(line);
            int value;
            while (lineStream >> value)
                lineData.push_back(value);
            if(lineData.size() == size){
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
    // szerokość pola wyświetlania
    const int fieldWidth = 4;
    std::cout << "Graph as matrix" << std::endl;

    // wyswietlanie naglowkow kolumn
    std::cout << std::setw(fieldWidth) << " " << " | ";
    for (int j = 0; j < vertices; j++) {
        std::cout << std::setw(fieldWidth) << j << " ";
    }
    std::cout << std::endl;

    // wyswietlanie linii separatora
    std::cout << std::setfill('-') << std::setw(fieldWidth + 1) << "" << "+" << std::setw((fieldWidth + 1) * vertices) << "" << std::setfill(' ') << std::endl;

    // wyswietlanie zawartosci tablicy
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
