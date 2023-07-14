#include<bits/stdc++.h>

bool dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis)
{   
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==-1)
        {
            if(dfs(it,node,adj,vis))
              return true;
        }
        else if(it!=parent)
          return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(auto it:edges)
    {
        adj[it[0]-1].push_back(it[1]-1);
        adj[it[1]-1].push_back(it[0]-1);
    }

    vector<int> vis(n,-1);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==-1)
        {
            if(dfs(i,-1,adj,vis))
              return "Yes";
        }
    }
    return "No";
}
