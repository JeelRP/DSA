#include <bits/stdc++.h>
using namespace std;

vector<int> topoBFS(int v, vector<int> adj[])
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
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
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
    vector<int> ans = topoBFS(u, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}