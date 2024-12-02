// Heap.h
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

typedef struct {
    int pos;
    int keyvalue;
} min_node;

void min_heapify(min_node A[], int i, int t);
void build_heap(min_node A[], int t);
min_node extract_min(min_node A[], int &t);
void decrease_key(min_node A[], int i, int key);

#endif // HEAP_H
