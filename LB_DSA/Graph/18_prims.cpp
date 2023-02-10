#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> prims(int n, int m, vector<pair<pair<int, int> int>> &g)
{
    unordered_map<int, list<pair<int int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adl[u].push_back(make_pair(v, w));
        adl[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1);
    vector<int> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++)
        {
            if (mst[v] = false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        mst[v] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] = false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main()
{
    int u, v;
    cin >> u;

    cin >> v;

    vector<int> adj[u];
    for (int i = 0; i < v; i++)
    {
        int n, m, w;
        cin >> n >> m >> w;
        adj[n].push_back(m);
    }
    return 0;
}