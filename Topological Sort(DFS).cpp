#include <bits/stdc++.h> 

void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==-1)
          dfs(it,adj,vis,st);
    }

    st.push(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(auto it:edges)
      adj[it[0]].push_back(it[1]);

    stack<int> st;
    vector<int> vis(v,-1);
    for(int i=0;i<v;i++)
    {
        if(vis[i]==-1)
          dfs(i,adj,vis,st);
    }

    vector<int> ans;
    while(!st.empty())
    {
        int a=st.top();
        st.pop();
        ans.push_back(a);
    }
    return ans;

}
