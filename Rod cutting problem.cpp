#include<bits/stdc++.h>

int f(int idx,vector<int> &price, int n,vector<int> &dp)
{
	if(idx==n)
	  return 0;
	
	if(dp[idx]!=-1)
	  return dp[idx];

	int ans=INT_MIN;
	for(int i=idx;i<n;i++)
	{
		int cost=price[i-idx]+f(i+1,price,n,dp);
		ans=max(ans,cost);
	}

	return dp[idx]=ans;
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n,-1);
	return f(0,price,n,dp);
}
