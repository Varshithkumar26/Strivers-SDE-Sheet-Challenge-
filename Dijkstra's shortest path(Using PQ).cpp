#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto it:vec)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<int> dist(vertices,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[source]=0;
    pq.push({0,source});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int vertex=it.first;
            int distance=it.second;
            if(dist[vertex]>d+distance)
            {
                dist[vertex]=d+distance;
                pq.push({distance+d,vertex});
            }
        }
    }


    return dist;
}
