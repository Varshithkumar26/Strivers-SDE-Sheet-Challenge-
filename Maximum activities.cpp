#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    vector<vector<int>> arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({finish[i],start[i]});
    }

    sort(arr.begin(),arr.end());
    
    int ans=0;
    int endtime=-1;
    for(auto it:arr)
    {
        if(endtime<=it[1])
        {
            endtime=it[0];
            ans++;
        }
    }
    return ans;
}
