// Union.cpp
#include "Union.h"


int find_set(int x,int parent[])
{
    if(x!=parent[x])
    {
        parent[x]=find_set(parent[x], parent);
    }
    return parent[x];
}

void link(int x, int y, int rank[], int parent[]) 
{
    if (rank[x] > rank[y])
        parent[y] = x;
    else 
    {
        parent[x] = y;
        if (rank[x] == rank[y]) 
            rank[y]++;
    }
}

void Union(int x, int y,int rank[], int parent[])
{
    link(find_set(x,parent),find_set(y,parent),rank,parent);
}

