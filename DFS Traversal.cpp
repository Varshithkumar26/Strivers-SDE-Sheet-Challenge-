#include<bits/stdc++.h>

void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &a)
{
    if(vis[node]!=-1)
      return;
    
    vis[node]=1;
    a.push_back(node);
    for(auto it:adj[node])
      dfs(it,adj,vis,a);
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(V,-1);
    int cnt=0;//to find the number of connected components
    vector<vector<int>> ans;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==-1)
        {
            vector<int> a;
            cnt++;
            dfs(i,adj,vis,a);
            ans.push_back(a);
        }
    }

    return ans;

}
