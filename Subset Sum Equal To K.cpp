#include <bits/stdc++.h> 

bool f(int idx,int n, int k, vector<int> &arr,vector<vector<int>> &dp)
{
    if(idx==n)
    {
        if(k==0)
          return true;
        return false;
    }

    if(dp[idx][k]!=-1)
      return dp[idx][k];

    bool not_pick=f(idx+1,n,k,arr,dp);
    bool pick=false;
    if(arr[idx]<=k)
      pick=f(idx+1,n,k-arr[idx],arr,dp);

    return dp[idx][k]=pick||not_pick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // return f(0,n,k,arr,dp);

    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[n][0]=1;
    for(int idx=n-1;idx>=0;idx--)
    {
        for(int j=0;j<=k;j++)
        {
            bool not_pick=dp[idx+1][j];
            bool pick=false;
            if(arr[idx]<=j)
            pick=dp[idx+1][j-arr[idx]];

            dp[idx][j]=pick||not_pick;
        }
    }

    return dp[0][k];
}
