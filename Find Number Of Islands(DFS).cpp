#include<bits/stdc++.h>

void dfs(int row,int col,int** arr, int n, int m,vector<vector<int>> &vis)
{
   vis[row][col]=1;
   vector<vector<int>> dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
   for(auto it:dir)
   {
      int nrow=row+it[0];
      int ncol=col+it[1];
      if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && vis[nrow][ncol]==-1 && arr[nrow][ncol]==1)
        dfs(nrow,ncol,arr,n,m,vis);
   }

   return;
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int cnt=0;
   vector<vector<int>> vis(n,vector<int>(m,-1));
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(arr[i][j]==1 && vis[i][j]==-1)
         {
            cnt++;
            dfs(i,j,arr,n,m,vis);
         }
      }
   }

   return cnt;
}
