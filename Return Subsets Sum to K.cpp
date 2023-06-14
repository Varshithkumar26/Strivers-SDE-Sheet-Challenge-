#include<bits/stdc++.h>

void f(int idx,int sum, vector<int> arr,vector<int>&ds,vector<vector<int>>&ans)
{
    if(idx==arr.size())
    {
        if(sum==0)
          ans.push_back(ds);
        return;
    }

    f(idx+1,sum,arr,ds,ans);
    ds.push_back(arr[idx]);
    f(idx+1,sum-arr[idx],arr,ds,ans);
    ds.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    f(0,k,arr,ds,ans);
    return ans;
}
