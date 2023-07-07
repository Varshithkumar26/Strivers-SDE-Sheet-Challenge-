#include <bits/stdc++.h> 

int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(i==grid.size()-1 && j==grid[0].size()-1)
      return grid[i][j];
    
    if(dp[i][j]!=-1)
      return dp[i][j];

    int down=1e9;
    if(i<grid.size()-1)
      down=grid[i][j]+f(i+1,j,grid,dp);
    int right=1e9;
    if(j<grid[0].size()-1)
      right=grid[i][j]+f(i,j+1,grid,dp);
    
    return dp[i][j]=min(down,right);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(0,0,grid,dp);
}
