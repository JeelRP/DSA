#include <bits/stdc++.h>
using namespace std;

bool BFS(int src, unordered_map<int, bool> &visited, vector<int> adj[])
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (visited[i] == true && parent[front] != i)
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
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
            bool ans = BFS(i, visited, adj);
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
