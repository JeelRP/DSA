#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, vector<int> adj[], vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, ans);
        }
    }
    return ans;
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

    vector<int> ans = dfsOfGraph(u, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}