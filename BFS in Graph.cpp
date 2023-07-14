#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> adj(vertex);
    for(auto it:edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    for(int i=0;i<vertex;i++)
      sort(adj[i].begin(),adj[i].end());//since order of printing the connected needs to be in sorted order

    vector<int> ans;
    vector<int> vis(vertex,-1);
    for(int i=0;i<vertex;i++)
    {
        if(vis[i]==-1)
        {   
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int size=q.size();
                for(int j=0;j<size;j++)
                {
                    int node=q.front();
                    q.pop();
                    ans.push_back(node);
                    for(auto it:adj[node])
                    {
                        if(vis[it]==-1)
                        {
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        
    }
    

    return ans;
}
