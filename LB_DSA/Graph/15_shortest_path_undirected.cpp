#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathUndirected(int v, vector<int> adj[], int s, int t)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int currentNode = t;
    ans.push_back(currentNode);
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());

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
    vector<int> ans = shortestPathUndirected(u, adj, 0, 7);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}