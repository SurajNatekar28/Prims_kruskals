// Kruskal.cpp
#include "Kruskal.h"
#include "Union.h"
//#include "mergesort.h"
//#include "GraphAdt.h"

int kruskal_algo(Graph* G) 
{
    int cost=0;
    //edge A[G->ne];
    G->kruskals_graph = (edge*) malloc(G->ne * sizeof(edge));
    int rank[G->v]={0};
    int parent[G->v];

    for(int i=0; i<G->v; i++)
    { 
      parent[i]=i;
    }

    mergeSort(G->edgelist,0,G->ne-1);

   int y=0;                //number of edges in kruskal graph
    for(int i=0; i<G->ne; i++)
    {
        if( find_set(G->edgelist[i].u,parent) != find_set(G->edgelist[i].v,parent) )
        {
            G->kruskals_graph[y].u=G->edgelist[i].u;
            G->kruskals_graph[y].v=G->edgelist[i].v;
            G->kruskals_graph[y].w=G->edgelist[i].w;
            y++;
            Union(G->edgelist[i].u,G->edgelist[i].v,rank,parent);
        }
    }

    for(int j=0; j<y; j++)
    { 
        cost+=G->kruskals_graph[j].w;
    }
    cout<<"Kruskal's algorithm MST:"<<endl;
    cout<<"Total cost- "<<cost<<endl;

    //print_kruskals(G,y);
    
    return y;
}





void merge(edge arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    edge leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
    {
        leftArr[i].u = arr[left + i].u;
        leftArr[i].v = arr[left + i].v;
        leftArr[i].w = arr[left + i].w;
    }
    for (j = 0; j < n2; j++)
    {
        rightArr[j].u = arr[mid + 1 + j].u;
        rightArr[j].v = arr[mid + 1 + j].v;
        rightArr[j].w = arr[mid + 1 + j].w;
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    {
        if (leftArr[i].w <= rightArr[j].w) 
        {
            arr[k].u = leftArr[i].u;
            arr[k].v = leftArr[i].v;
            arr[k].w = leftArr[i].w;
            i++;
        }
        else 
        {
            arr[k].u = rightArr[j].u;
            arr[k].v = rightArr[j].v;
            arr[k].w = rightArr[j].w;
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k].u = leftArr[i].u;
        arr[k].v = leftArr[i].v;
        arr[k].w = leftArr[i].w;
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k].u = rightArr[j].u;
        arr[k].v = rightArr[j].v;
        arr[k].w = rightArr[j].w;
        j++;
        k++;
    }
}

void mergeSort(edge arr[], int left, int right) 
{
    if (left < right) 
    {
      
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
