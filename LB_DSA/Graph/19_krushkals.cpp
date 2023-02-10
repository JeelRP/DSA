#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b)
{
    return a[2]<b[2];
}
makeSet(vector<int>&parent, vector<int>&rank, int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int>&parent, int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node]=findParent(parent,node);
}

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank)
{
    u=findParent(parent,u);
    v=findParent(parent,v);

    if(rank[u] < rank[v])
    {
        parent[u]=v;
        
    }
    else if(rank[u] > rank[v])
    {
        parent[v]=u;
        
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}
minimumSpanningTree(vector<vector<int>>&edges, int n)
{
    sort(edges.begin(),edges.end(), cmp);
    vector<int>parent;
    vector<int>rank;
    makeSet(parent,rank,n);

    int minweight=0;
    for(int i=0; i<edges.size(); i++)
    {
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];

        if(u!=v)
        {
            minweight+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minweight;
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
    return 0;
}