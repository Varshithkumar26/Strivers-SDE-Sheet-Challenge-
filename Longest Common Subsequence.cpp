#include<bits/stdc++.h>

int f(int i,int j,string s, string t,vector<vector<int>> &dp)
{
	if(i==0 || j==0)
	  return 0;

	if(dp[i][j]!=-1)
	  return dp[i][j];
	
	int ans;
	if(s[i-1]==t[j-1])
	  ans=1+f(i-1,j-1,s,t,dp);
	else
	  ans=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
	
	return dp[i][j]=ans;
}

int lcs(string s, string t)
{
	//Write your code here
	int m=s.length(),n=t.length();
	// vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	// //return f(m,n,s,t,dp);

	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	for(int i=0;i<m;i++)
	  dp[i][0]=0;
	for(int j=0;j<n;j++)
	  dp[0][j]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			  dp[i][j]=1+dp[i-1][j-1];
			else
			  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	return dp[m][n];
}
