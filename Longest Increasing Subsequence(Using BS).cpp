#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    int ans=0;
    vector<int> dp;
    dp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        int idx=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
        if(idx==dp.size())
          dp.push_back(arr[i]);
        else
          dp[idx]=arr[i];
    }
    return dp.size();

    
}
