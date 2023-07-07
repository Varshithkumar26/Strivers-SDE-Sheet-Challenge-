#include <bits/stdc++.h> 

int f(int idx,int pidx,vector<int> &rack, int n,vector<vector<int>> &dp)
{
	if(idx==n)
	  return 0;
	
	if(dp[idx][pidx+1]!=-1)
	  return dp[idx][pidx+1];

	int not_pick=f(idx+1,pidx,rack,n,dp);
	int pick=0;
	if(pidx==-1 || rack[idx]>rack[pidx])
	  pick=rack[idx]+f(idx+1,idx,rack,n,dp);
	
	return dp[idx][pidx+1]=max(pick,not_pick);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return f(0,-1,rack,n,dp);

}
