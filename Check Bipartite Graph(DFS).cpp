#include<bits/stdc++.h>

bool dfs(int node,vector<vector<int>>&adj,vector<int> &color,int col)
{
    color[node]=col;
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
          if(dfs(it,adj,color,col^1)==false)
            return false;
        }
        else if(color[it]==col)
          return false;
        
    }
    return true;
    
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int v=edges.size();
	vector<vector<int>> adj(v);
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(edges[i][j]==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> color(v,-1);
	for(int i=0;i<v;i++)
	{
		if(color[i]==-1)
		{
			if(!dfs(i,adj,color,0))
			  return false;
		}
	}
	return true;

}
