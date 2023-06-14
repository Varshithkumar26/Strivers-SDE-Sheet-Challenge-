#include <bits/stdc++.h> 

void f(int idx,vector<int> &num,int sum,vector<int> &ds)
{
    if(idx==num.size())
    {
        ds.push_back(sum);
        return;
    }

    f(idx+1,num,sum,ds);
    f(idx+1,num,sum+num[idx],ds);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int sum=0;
    vector<int> ans;
    f(0,num,sum,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
