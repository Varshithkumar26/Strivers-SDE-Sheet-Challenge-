#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    // Write your code here.
    int mini=INT_MAX;
    int ans=0;
    for(auto it:p)
    {
        mini=min(mini,it);
        ans=max(ans,it-mini);
    }
    return ans;
}
