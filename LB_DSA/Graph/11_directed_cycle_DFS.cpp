#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, vector<int> adj[])
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool cycleDetect = detectCycle(i, visited, dfsVisited, adj);
            if (cycleDetect)
            {
                return true;
            }
        }
        else if (dfsVisited[i])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int v, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = detectCycle(i, visited, dfsVisited, adj);
            if (cycleFound)
            {
                return true;
            }
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
    }

    bool ans = detectCycleInDirectedGraph(u, adj);

    cout << ans;
    return 0;
}