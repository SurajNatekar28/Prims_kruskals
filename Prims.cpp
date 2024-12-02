// Prim.cpp
#include "Prims.h"
#include "Heap.h"

void Prims_algo(Graph* G) 
{
    int heap_size;
    int parent[G->v];
    bool mst[G->v];
    min_node key[G->v],u;

    for(int i=0; i<G->v; i++)
    {
        G->parent[i] = -1;
        key[i].keyvalue = INT_MAX;
        key[i].pos=i;
        mst[i] = false;
    }

    heap_size=G->v;
    key[0].keyvalue=0;
    build_heap(key,heap_size);
    int count=0;

    while(heap_size!=0)
    {
        u=extract_min(key,heap_size);                   //extract min
       // heap_size=heap_size-1;
        mst[u.pos] = true;  
        count=count+u.keyvalue;
       // cout<<" "<<u.pos<<" "<<u.keyvalue<<endl;
       for(int j=0; j< G->v; j++)
       {
            int cost;
            cost= G->cost_matrix[u.pos][j];
            
            if(cost != INT_MAX && !mst[j])
            {
                for(int i=0; i<heap_size; i++)
                {
                    if(j== key[i].pos && cost<key[i].keyvalue)
                    {
                        G->parent[j]=u.pos;
                        decrease_key(key,i,cost);         //decreasse key 
                    }
                }
            }
       }

    }
    cout<<"Prim's algorithm MST:"<<endl;
    cout<<"Total cost- "<<count<<endl;           //final cost
    
    // print_prims(G,parent);
}
