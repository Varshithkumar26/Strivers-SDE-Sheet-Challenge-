#include <bits/stdc++.h> 

void f(int i,int j,vector<vector<int>> &maze,int n,vector<vector<int>> &ds,vector<vector<int>> &ans)
{
  if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 || ds[i][j]==1)
    return;
  
  ds[i][j]=1;

  if(i==n-1 && j==n-1)
  {
      vector<int> a;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
          a.push_back(ds[i][j]);
      }
      ans.push_back(a);
      ds[i][j]=0;
      return;
  }
  
  f(i+1,j,maze,n,ds,ans);
  f(i,j-1,maze,n,ds,ans);
  f(i,j+1,maze,n,ds,ans);
  f(i-1,j,maze,n,ds,ans);
  
  ds[i][j]=0;

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ds(n,vector<int>(n,0));
  vector<vector<int>> ans;
  f(0,0,maze,n,ds,ans);
  return ans;

}
