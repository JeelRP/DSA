// main function is wrong

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> &vec, int edges, int src)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dist(v);

    // creation of distance array with infinite value initially
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }

    // creation of set on basis(distance, node)
    set<pair<int, int>> s;

    // initialise distance and set with source node
    dist[src] = 0;
    s.insert(make_pair(0, src));

    while (!s.empty())
    {
        // fetch top record
        auto top = *(s.begin());

        int distNode = top.first;
        int topNode = top.second;

        // remove top record
        s.erase(st.begin());

        // traverse all neighbours
        for (auto i : adj[topNode])
        {
            if (distNode + i.second < dist[i.first])
            {
                auto record = s.find(make_pair(dist[i.first], i.first));

                if (record != s.end())
                {
                    s.erase(record);
                }
            }
            // distance update
            dist[i.first] = distNode + i.second;

            // record push in set
            s.insert(make_pair(dist[i.first], i.first));
        }
    }
    return dist;
}

int main()
{
    int u = 5;
    int v = 7;

    vector<vector<int, int>> adj = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};

    vector<int> ans = dijkstra(u, adj, v, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// int main()
// {
//     int u = 5;
//     int v = 7;
//     vector<vector<int, int>> adj = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};

//     vector<int> ans = dijkstra(u, adj, v, 0);
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }