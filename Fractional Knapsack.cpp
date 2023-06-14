#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double,pair<int,int>>> arr;
    for(int i=0;i<n;i++)
    {
        double per=(1.0*items[i].second)/(1.0*items[i].first);
        arr.push_back({per,{items[i].first,items[i].second}});
    }

    sort(arr.rbegin(),arr.rend());
    double ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].second.first<=w)
        {
            ans=ans+arr[i].second.second;
            w-=arr[i].second.first;
        }
        else
        {
            ans=ans+((1.0*arr[i].first)*(1.0*w));
            break;
        }
    }
    return ans;
}
