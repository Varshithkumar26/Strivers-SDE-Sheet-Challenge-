#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    vector<int> temp=intervals[0];
    for(auto it:intervals)
    {
        if(temp[1]>=it[0])
          temp[1]=max(temp[1],it[1]);
        else
        {
            ans.push_back(temp);
            temp=it;
        }
    }

    ans.push_back(temp);;
    return ans;

}
