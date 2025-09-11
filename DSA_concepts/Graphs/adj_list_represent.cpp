#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adj;
    // vector<vector<int>> adj; without cost element
public:
    Graph() {}
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int cost, bool directed)
    {
        adj[u].push_back(make_pair(v, cost)); //        adj[u].push_back(v); without cost element
        if (directed == false)
        {
            adj[v].push_back(make_pair(u, cost));
        }
    }

    void display_adj_list()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << ":";
            for (auto &ele : adj[i])
            {
                cout << "(" << ele.first << "," << ele.second << ")->";
            }
            cout << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    Graph obj1(3);
    Graph obj2(3);

    cout<<"Adjacemcy list of Directed graph: "<<endl;
    obj1.addEdge(0,1,5,true);
    obj1.addEdge(0,2,6,true);
    obj1.addEdge(1,2,8,true);

    obj1.display_adj_list();

    cout<<"Adjaceny list of Undirected graph:"<<endl;

    obj2.addEdge(0,1,5,false);
    obj2.addEdge(0,2,6,false);
    obj2.addEdge(1,2,8,false);

    obj2.display_adj_list();



    return 0;
}
