#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int deadline=0;
    vector<vector<int>> j;
    for(auto it:jobs)
    {
        j.push_back({it[1],it[0]});
        deadline=max(deadline,it[0]);
    }
      

    sort(j.begin(),j.end());
    reverse(j.begin(),j.end());
    vector<int> d(deadline+1,-1);

    int profit=0;
    for(auto it:j)
    {
        int idx=it[1];
        while(idx>0 && d[idx]!=-1)
          idx--;
        if(idx>0)
        {
            d[idx]=it[1];
            profit+=it[0];
        }
    }

    return profit;
}
