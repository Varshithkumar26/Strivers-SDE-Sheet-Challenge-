#include <bits/stdc++.h> 

int helper(vector<int>&arr,int start,int end,vector<vector<int>>&dp) 
{
    if(start==end)
      return 0;

    if(dp[start][end]!=-1)
      return dp[start][end];

    int res=INT_MAX;
    for(int i=start;i<end;i++)
    {
        int oper=arr[start-1]*arr[i]*arr[end]+helper(arr,start,i,dp)+helper(arr,i+1,end,dp);
        res=min(res,oper);
    }    

    return dp[start][end]=res;


}

int matrixMultiplication(vector<int> &arr, int N) {
    // vector<vector<int>>dp(N,vector<int>(N,-1));
    // return helper(arr,1,N-1,dp);//start should start from 1

    vector<vector<int>>dp(N,vector<int>(N,-1));
    for(int i=0;i<N;i++)
      dp[i][i]=0;
    
    for(int i=N-1;i>=1;i--)
    {
        for(int j=i+1;j<N;j++)
        {
            int res=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int oper=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                res=min(res,oper);
            }    

            dp[i][j]=res;
        }
    }

    return dp[1][N-1];
}
