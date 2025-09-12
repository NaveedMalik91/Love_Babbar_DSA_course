#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Graph class to represent the graph and perform Prim's algorithm
class Graph
{
private:
    int V;
    // Adjacency list to store the graph
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices)
    {
        this->V = vertices;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int cost)
    {
        adjList[u].push_back(make_pair(v, cost));
        adjList[v].push_back(make_pair(u, cost));
    }

    // Function to find minimum value index in key array
    int getMinValIndex(int key[], bool mst[])
    {
        int minVal = INT_MAX; //set values of all vertices to infinite 
        int minIndex = -1;
        for (int i = 0; i < V; i++)
        {
            if (key[i] < minVal && !mst[i])
            {
                minVal = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Function to find minimum cost spanning tree using Prim's algorithm
    void primMST()
    {
        int key[V], parent[V];
        bool mst[V];

        // Initialize key values, parent and mst set for all vertices
        for (int i = 0; i < V; i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }

        key[0] = 0; // Start from vertex 0

        while (true)
        {
            int u = getMinValIndex(key, mst);

            if (u == -1) // Exit condition when no more vertices are there
                break;

            mst[u] = true;

            // jo b current node hai uski adjacency list dekho
            for (auto edge : adjList[u])
            {
                int dest = edge.first; 
                int cost = edge.second;
                //compare the cost of
                if (cost < key[dest] && !mst[dest]) 
                {
                    parent[dest] = u; //vertex having least cost will become parent
                    key[dest] = cost; //connect to minimum cost vertex
                }
            }
        }

        cout << "\nMinimum Spanning Tree:" << endl;
        cout << "Edge\tWeight" << endl;
        int minCost = 0;
        for (int i = 1; i < V; i++)
        {
            cout << parent[i] << " <-> " << i << "\t" << key[i] << endl;
            minCost += key[i];
        }
        cout << "Minimum total cost: " << minCost << endl;
    }
};

int main()
{
   
    int ver;
    Graph graph(ver);

    graph.addEdge(0,1,3);
    

    graph.primMST();

    return 0;
}