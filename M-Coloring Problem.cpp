#include <bits/stdc++.h> 

bool possible(int node,vector<vector<int>> &graph, int a,vector<int>&col)
{
    for(auto it:graph[node])
    {
        if(col[it]==a)
          return false;
    }
    return true;
}

bool f(int node,vector<vector<int>> &graph, int m,vector<int>&col)
{
    if(node==graph.size())
      return true;
    
    for(int i=0;i<m;i++)
    {
        if(possible(node,graph,i,col))
        {
            col[node]=i;
            if(f(node+1,graph,m,col))
              return true;
            col[node]=-1;
        }   
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==1)
            {
                graph[i].push_back(j);
                //graph[j].push_back(i);
            }
        }
    }
    
    int node=0;
    vector<int> col(n,-1);
    if(f(node,graph,m,col))
      return "YES";

    return "NO";
}
