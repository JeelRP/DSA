#include <bits/stdc++.h>
using namespace std;

void solve(int node, unordered_map<int, bool> &visited, stack<int> &s, vector<int> adj[])
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            solve(i, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topoDFs(int v, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            solve(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    int u, v;
    cin >> u;

    cin >> v;

    vector<int> adj[u];
    for (int i = 0; i < v; i++)
    {
        int n, m;
        cin >> n >> m;
        adj[n].push_back(m);
    }

    vector<int> ans = topoDFs(u, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}