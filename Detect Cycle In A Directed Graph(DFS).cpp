#include<bits/stdc++.h>

bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathvis)
{  
  vis[node]=1;
  pathvis[node]=1;
  for(auto it:adj[node])
  {
    if(vis[it]==-1)
    {
      if(dfs(it,adj,vis,pathvis))
        return true;
    }
    else if(vis[it]==1 && pathvis[it]==1)
      return true;
    
  }
  pathvis[node]=-1;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
      vector<vector<int>> adj(n);
      for(auto it:edges)
      {
          adj[it.first-1].push_back(it.second-1);
      }

      vector<int> vis(n,-1);
      vector<int> pathvis(n,-1);
      for(int i=0;i<n;i++)
      {
        if(vis[i]==-1)
        {
          if(dfs(i,adj,vis,pathvis))
            return true;
        }
      }

      return false;
}
