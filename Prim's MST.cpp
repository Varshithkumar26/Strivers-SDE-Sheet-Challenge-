#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:g)
    {
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }
      
    vector<pair<pair<int, int>,int>> ans;
    vector<int> visited(n+1,-1);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,  greater<pair<int, pair<int, int>>>> pq;
    //{wt,{node,parent}}
    pq.push({0,{1,-1}});
    while(!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(visited[node]==1)
            continue;
        visited[node] = 1;
        if(parent!=-1)
          ans.push_back({{parent,node},weight});
        for(auto it:adj[node])
        {
            int adjvertex=it.first;
            int edgewt=it.second;
            if(visited[adjvertex]==-1)
              pq.push({edgewt,{adjvertex,node}});
        }
    }

    return ans;

}
