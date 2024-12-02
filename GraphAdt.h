// GraphADT.h
#ifndef GRAPH_ADT_H
#define GRAPH_ADT_H

#include <fstream>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <climits>
using namespace std;
#define MAX_VERTICES 100

typedef struct {
    int u;              //vertex u
    int v;              //vertex v
    int w;              //weight between u-v
} edge;

typedef struct {
    int v;                  //no. of vertices
    int ne;                 //number of edges
    int** cost_matrix;
    edge* edgelist;         
    edge* kruskals_graph;       //kruskals graph instance
    int parent[MAX_VERTICES];   //prims graph instance
} Graph;

Graph* initialize_Graph(const std::string& filename);

#endif // GRAPH_ADT_H
