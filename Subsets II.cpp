#include <bits/stdc++.h> 

void f(int idx,int n, vector<int> &arr,vector<int>&ds,vector<vector<int>>&ans)
{
    ans.push_back(ds);
    for(int i=idx;i<n;i++)
    {
        if(i!=idx && arr[i]==arr[i-1])
          continue;
        ds.push_back(arr[i]);
        f(i+1,n,arr,ds,ans);
        ds.pop_back();
    }
    return;
    
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    f(0,n,arr,ds,ans);
    return ans;
}
