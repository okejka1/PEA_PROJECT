//
// Created by User on 13.10.2023.
//

#ifndef PEA_GRAPH_H
#define PEA_GRAPH_H


#include <string>

class Graph {
private:
public:
    int **edges; // krawędzie grafu
    int vertices; // liczba wierzchołków
    Graph(int v);
    void readGraphDirected(std::string s, int size);
    void addEdge(int u, int v, int w);
    void display() const;

    virtual ~Graph();

};



#endif //PEA_GRAPH_H
