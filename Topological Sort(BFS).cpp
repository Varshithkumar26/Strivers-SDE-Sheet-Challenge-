#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    vector<int> indegree(v,0);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }

    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
          q.push(i);
    }

    vector<int> ans;
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                  q.push(it);
            }
        }
    }
    return ans;

}
