#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int xr=0;
    int cnt=0;
    unordered_map<int,int> mp;
    //mp[0]=1;
    for(auto it:arr)
    {
        xr^=it;
        if(xr==x)
          cnt++;
        if(mp.find(xr^x)!=mp.end())
          cnt+=mp[xr^x];
        mp[xr]++;
    }
    return cnt;
}
