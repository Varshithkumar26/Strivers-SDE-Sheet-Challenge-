#include <bits/stdc++.h> 

void f(int idx,vector<int>&v,vector<int>&ds,vector<vector<int>> &ans)
{
    if(idx==v.size())
    {
        ans.push_back(ds);
        return;
    }

    f(idx+1,v,ds,ans);
    ds.push_back(v[idx]);
    f(idx+1,v,ds,ans);
    ds.pop_back();
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<int> ds;
    vector<vector<int>> ans;
    f(0,v,ds,ans);
    return ans;
}
