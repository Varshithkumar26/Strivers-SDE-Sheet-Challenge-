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
    set<pair<int,int>> st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0)
    {
        auto it=*(st.begin());
        int distance=it.first;
        int node=it.second;
        st.erase({distance,node});
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int edgewgt=it.second;
            if(dist[adjnode]>distance+edgewgt)
            {
                if(dist[adjnode]!=INT_MAX)
                  st.erase({dist[adjnode],adjnode});
                dist[adjnode]=distance+edgewgt;
                st.insert({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}
