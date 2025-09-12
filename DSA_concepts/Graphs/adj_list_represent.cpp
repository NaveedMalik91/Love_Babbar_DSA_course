#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
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

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << ": {  ";
            for (pair<T, int> p : i.second)
            {
                cout << "{" << p.first << ", " << p.second << "}, ";
            }
            cout << "}" << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    Graph<int> obj2;
    Graph<char> obj1;

    cout << "Adjacemcy list of Directed graph: " << endl;
    obj1.addEdge('a', 'b', 5, true);
    obj1.addEdge('a', 'c', 6, true);
    obj1.addEdge('b', 'c', 8, true);

    obj1.printAdjList();

    cout << "Adjaceny list of Undirected graph:" << endl;

    obj2.addEdge(0, 1, 5, false);
    obj2.addEdge(0, 2, 6, false);
    obj2.addEdge(1, 2, 8, false);

    obj2.printAdjList();

    return 0;
}
