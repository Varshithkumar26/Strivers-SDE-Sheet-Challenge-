#include<bits/stdc++.h>

int f(int idx,vector<int> &values, vector<int> &weights, int n, int w,vector<vector<int>> &dp)
{
	if(idx==n)
	  return 0;
	
	if(dp[idx][w]!=-1)
	  return dp[idx][w];

	int not_pick=f(idx+1,values,weights,n,w,dp);
	int pick=0;
	if(weights[idx]<=w)
	  pick=values[idx]+f(idx+1,values,weights,n,w-weights[idx],dp);
	
	return dp[idx][w]=max(pick,not_pick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	//vector<vector<int>> dp(n,vector<int>(w+1,-1));
	//return f(0,values,weights,n,w,dp);

	vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
	for(int i=0;i<=w;i++)
	  dp[n][i]=0;
	
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=w;j++)
		{
			int not_pick=dp[i+1][j];
			int pick=0;
			if(weights[i]<=j)
			 pick=values[i]+dp[i+1][j-weights[i]];
			
			dp[i][j]=max(pick,not_pick);
			ans=max(ans,dp[i][j]);
		}
	}

	return ans;
}
