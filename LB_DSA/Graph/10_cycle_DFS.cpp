#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, int parent, unordered_map<int, bool> &visited, vector<int> adj[])
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool cycleDetected = DFS(i, node, visited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (i != node)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = DFS(i, -1, visited, adj);
            if (ans == true)
                return true;
        }
    }
    return false;
}

int main()
{

    int u, v;
    cout << "Enter Number of Nodes : ";
    cin >> u;

    cout << "Enter Number of Edges : ";
    cin >> v;

    vector<int> adj[u];

    for (int i = 0; i < v; i++)
    {
        int n, m;
        cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }

    bool ans = isCycle(u, adj);

    cout << ans;
    return 0;
}
