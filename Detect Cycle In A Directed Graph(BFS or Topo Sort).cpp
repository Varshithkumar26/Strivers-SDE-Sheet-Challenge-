#include <bits/stdc++.h> 
int topologicalSort(vector<pair<int,int>> &edges, int v)  
{

    vector<vector<int>> adj(v);
    vector<int> indegree(v,0);
    for(auto it:edges)
    {
        adj[it.first-1].push_back(it.second-1);
        indegree[it.second-1]++;
    }

    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
          q.push(i);
    }

    int cnt=0;
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                  q.push(it);
            }
        }
    }
    return cnt;
}

int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
  // Write your code here.
  
  int cnt=topologicalSort(edges,v);//IDEA: Topo sort is valid only on DAG graphs so if cnt==(no of vertices) then there is no cycle 
  if(cnt==v)
    return false;
  return true;
  
}
