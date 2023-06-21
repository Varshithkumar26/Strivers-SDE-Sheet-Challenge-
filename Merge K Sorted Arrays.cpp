#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here.
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0;i<k;i++)
      pq.push({-arr[i][0],{i,0}});
    
    vector<int> ans;
    while(!pq.empty())
    {
        int ele=-pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        ans.push_back(ele);
        if(col<arr[row].size()-1)
         pq.push({-arr[row][col+1],{row,col+1}});
    }
    return ans;
      
}
