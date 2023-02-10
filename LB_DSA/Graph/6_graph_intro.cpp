#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // create graph
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int u, v;
    cout << "Enter Number of Nodes : ";
    cin >> u;

    cout << "Enter Number of Edges : ";
    cin >> v;

    graph g;

    for (int i = 0; i < v; i++)
    {
        int n, m;
        cin >> n >> m;
        g.addEdge(n, m, 1);
    }

    g.printAdjList();
    return 0;
}