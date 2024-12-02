// main.cpp
#include "GraphADT.h"
#include "Prims.h"
#include "Kruskal.h"
#include <chrono>

int main() 
{
    string filename = "input.txt";
    Graph* g=initialize_Graph(filename);

    //for checking invalidity
    int count=0;
    for(int i = 0; i < g->v; i++) 
    {
        count=0;
        for (int j = 0; j < g->v; j++) 
        {
            if(g->cost_matrix[i][j]==INT_MAX)
            {
                count++;
            }

        }
        if(count==g->v)
        {
            cout<<"MST does't exist"<<endl;
            return 0;
        }
    }

    auto startPrim = std::chrono::high_resolution_clock::now();
    Prims_algo(g);  //calling prims
    auto endPrim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> primDuration = endPrim - startPrim;

    //printing prims
    for(int k=1; k<g->v; k++)
    {
        cout<<"("<<k+1<<" - "<<g->parent[k]+1<<")"<<endl;
    }

    std::cout << "Prim's Algorithm running time: " << primDuration.count() << " seconds" << std::endl;

    cout << endl;

    auto startKruskal = std::chrono::high_resolution_clock::now();
    int r=kruskal_algo(g);   //calling kruskals
    auto endKruskal = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> kruskalDuration = endKruskal - startKruskal;

    //printing kruskals
    for(int k=0; k<r; k++)
    {
        cout<<"("<<g->kruskals_graph[k].u+1<<" - "<<g->kruskals_graph[k].v+1<<")"<<endl;
    }

    std::cout << "Kruskal's Algorithm running time: " << kruskalDuration.count() << " seconds" << std::endl;

    return 0;
}
