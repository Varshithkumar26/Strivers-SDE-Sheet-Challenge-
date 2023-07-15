#include<bits/stdc++.h>

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

	vector<int> col(v,-1);
	for(int i=0;i<v;i++)
	{
		if(col[i]==-1)
		{
			queue<pair<int,int>> q;
			q.push({i,0});
			col[i]=0;
			while(!q.empty())
			{
				int s=q.size();
				for(int j=0;j<s;j++)
				{
					int node=q.front().first;
					int color=q.front().second;
					q.pop();
					for(auto it:adj[node])
					{
						if(col[it]==-1)
						{
							q.push({it,color^1});
							col[it]=color^1;
						}
						else if(col[it]==color)
						  return false;
					}

				}
			}
		}
	}
	
	return true;

}
