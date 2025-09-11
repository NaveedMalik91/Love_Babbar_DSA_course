#include <iostream>
#include <vector>
using namespace std;
class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.assign(V, vector<int>(V, 0)); // initialize all values of 2D-vector to 0
    }

    void addEdge(int u, int v, bool directed)
    {
        adj[u][v] = 1;
        if (directed == false)
        {
            adj[v][u] = 1;
        }
    }

    void display_adj_matrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph obj1(3);
    cout<<"Adjacency matrix of Undirected graph:"<<endl;
    obj1.addEdge(0,1,false);
    obj1.addEdge(1,2,false);
    obj1.addEdge(0,2,false);
    obj1.display_adj_matrix();

    cout<<"Adjacency matrix of Directed graph:"<<endl;
    Graph obj2(3);
    obj2.addEdge(0,1,true);
    obj2.addEdge(0,2,true);
    obj2.addEdge(1,2,true);

    obj2.display_adj_matrix();

    return 0;
}
