#include<bits/stdc++.h>
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
            queue<pair<int,int>> q;
            q.push({i,-1});
            vis[i]=1;
            while(!q.empty())
            {
                int s=q.size();
                for(int j=0;j<s;j++)
                {
                    int node=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    for(auto it:adj[node])
                    {
                        if(vis[it]==-1)
                        {
                            q.push({it,node});
                            vis[it]=1;
                        }
                        else if(it!=parent)
                          return "Yes";
                    }
                }
            }

        }
    }
    return "No";
}
