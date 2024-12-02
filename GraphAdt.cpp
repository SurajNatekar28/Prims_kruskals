// GraphADT.cpp
#include "GraphADT.h"

Graph* initialize_Graph(const std::string& filename)
{
    Graph* G = (Graph*) malloc(sizeof(Graph));
    if (!G) 
    {
        std::cerr << "Memory allocation failed.\n";
        return nullptr;
    }

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    // Determine the number of vertices by counting rows in the file
    int rowCount = 0;
    std::string line;
    while (std::getline(inputFile, line)) 
    {
        ++rowCount;
    }
    G->v = rowCount;
    
    // Reset file stream to beginning for reading matrix
    inputFile.clear();
    inputFile.seekg(0);

    // Initialize the cost matrix 
    G->cost_matrix = (int**) malloc(G->v * sizeof(int*));
    for (int i = 0; i < G->v; i++) 
    {
        G->cost_matrix[i] = (int*) malloc(G->v * sizeof(int));
    }

    // Initialize the edge list with a maximum size
    int maxEdges = G->v * (G->v - 1) / 2;                   //as cost_matarix is symmetric
    G->edgelist = (edge*) malloc(maxEdges * sizeof(edge));
    G->ne = 0;

    // Read the cost matrix from the file
    for (int i = 0; i < G->v; i++) 
    {
        for (int j = 0; j < G->v; j++) 
        {
            int weight;
            inputFile >> weight;                    //take weight input from file
            if (weight == -1 || weight == 0) 
            {
                G->cost_matrix[i][j] = INT_MAX;     //make infinite whereever no edge
            } 
            else 
            {
                G->cost_matrix[i][j] = weight;
                // Store only edges of lower tringular matrix
                if (i < j && weight != INT_MAX)            
                {
                    G->edgelist[G->ne++] = {i, j, weight};  //make graph instance
                }
            }
        }
    }

    inputFile.close();
    return G;
}

