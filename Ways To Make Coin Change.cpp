#include<bits/stdc++.h>

long f(int idx,int *denominations, int n, int value,vector<vector<long>> &dp)
{
    if(idx==n)
    {
        if(value==0)
          return 1;
        return 0;
    }

    if(dp[idx][value]!=-1)
      return dp[idx][value];

    long not_pick=f(idx+1,denominations,n,value,dp);
    long pick=0;
    if(denominations[idx]<=value)
      pick=f(idx,denominations,n,value-denominations[idx],dp);
    
    return dp[idx][value]=pick+not_pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    //vector<vector<long>> dp(n,vector<long>(value+1,-1));
    //return f(0,denominations,n,value,dp);

    vector<vector<long>> dp(n+1,vector<long>(value+1,-1));
    dp[n][0]=1;
    for(int i=1;i<=value;i++)
      dp[n][i]=0;
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=value;j++)
        {
            long not_pick=dp[i+1][j];
            long pick=0;
            if(denominations[i]<=j)
              pick=dp[i][j-denominations[i]];
            
            dp[i][j]=pick+not_pick;
        }
    }

    return dp[0][value];
}
