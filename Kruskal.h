// Kruskal.h
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "GraphADT.h"

int kruskal_algo(Graph* G);
void merge(edge arr[], int left, int mid, int right);
void mergeSort(edge arr[], int left, int right);


#endif // KRUSKAL_H
