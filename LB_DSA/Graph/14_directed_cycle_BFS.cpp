#include <bits/stdc++.h>
using namespace std;

bool topoBFS(int v, vector<int> adj[])
{
    vector<int> indegree(v);

    // find all indegree

    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    // push every node contain 0 indegree

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do BFS
    int count;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;
        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (count == v)
    {
        return false;
    }
    else
    {
        return true;
    }
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
    bool ans = topoBFS(u, adj);

    cout << ans;
    return 0;
}