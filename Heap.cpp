// Heap.cpp
#include "Heap.h"


void min_heapify(min_node A[], int i, int t) 
{
    int left,smallest;
    int right,temp_value,temp_pos;
    left=2*i+1;
    right=2*i+2;

    if(left<=(t-1) && A[left].keyvalue<A[i].keyvalue)
    {
        smallest=left;
    }
    else
        smallest=i;

    if(right<= (t-1) && A[right].keyvalue<A[smallest].keyvalue)
    {
        smallest=right;
    }
    
    if(smallest != i)
    {
        temp_value=A[i].keyvalue;
        temp_pos=A[i].pos;

        A[i].keyvalue=A[smallest].keyvalue;
        A[i].pos=A[smallest].pos;

        A[smallest].keyvalue=temp_value;
        A[smallest].pos = temp_pos;

        min_heapify(A,smallest,t);
    }
}

void build_heap(min_node A[], int t) 
{
    int size=t;
    for(int i=size/2 - 1; i>=0; i--)
    {
        min_heapify(A,i,size);
    }
}

min_node extract_min(min_node A[], int &t) 
{
    if(t<1)
    {
        cout<<"Heap underflow"<<endl;
    }
    min_node minimum;
    minimum.keyvalue=A[0].keyvalue;
    minimum.pos=A[0].pos;

    A[0].keyvalue=A[t-1].keyvalue;
    A[0].pos=A[t-1].pos;

    t=t-1;
    min_heapify(A,0,t);
    return minimum;
    
}

void decrease_key(min_node A[], int i, int key) 
{
     int temp_value,temp_pos;
    if(key>A[i].keyvalue)
    {
        cout<<"error"<<endl;
    }
    A[i].keyvalue=key;

    while (i > 0 && A[(i - 1) / 2].keyvalue > A[i].keyvalue)
    {
        temp_value = A[i].keyvalue;
        temp_pos = A[i].pos;

        A[i].keyvalue = A[(i - 1) / 2].keyvalue;
        A[i].pos = A[(i - 1) / 2].pos;

        A[(i - 1) / 2].keyvalue = temp_value;
        A[(i - 1) / 2].pos = temp_pos;

        i = (i - 1) / 2;
    }
}
