#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <typename T> // so that any type of data fr node can be inserted
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool directed)
    {
        if (directed == 1)
        {
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void BFS(T src)
    {
        cout << "BFS traversal: ";
        queue<T> q;
        unordered_map<T, bool> visited; // data->visited(T/F)
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T frontval = q.front();
            cout << frontval << " ";
            q.pop();
            

            // go to neighbours
            for (auto nbr : adjList[frontval])
            {
                // get the first value of nbr i.e. node
                T nbrData = nbr.first;
                if (!visited[nbrData])
                {
                    q.push(nbrData);
                    visited[nbrData] = true;
                }
            }
        }
    }

    void DFS(T src,unordered_map<T,bool>&visited)
    {
        visited[src] = true;
        cout<<src<<" ";
        for(auto nbr : adjList[src]){
            T nbrData = nbr.first;
            if (!visited[nbrData])
            {
                DFS(nbrData,visited);
            }
            
        }
        

    }
};
int main(int argc, char const *argv[])
{
    Graph<char> obj1;
    obj1.addEdge('a', 'b', 5, false);
    obj1.addEdge('a', 'c', 6, false);
    obj1.addEdge('b', 'd', 8, false);
    obj1.addEdge('c', 'e', 9, false);
    obj1.addEdge('c', 'f', 9, false);
    obj1.addEdge('e', 'f', 9, false);

    

    obj1.BFS('a');
    cout<<endl;

    //printing the DFS for each node so that it handles evenin disconnected graph
    unordered_map<char,bool>visited;
    cout<<"DFS traversal:"<<endl;
    for(char node = 'a';node <= 'f'; node++){
        if(!visited[node]){
            obj1.DFS('a',visited);
        }
    }



    return 0;
}
