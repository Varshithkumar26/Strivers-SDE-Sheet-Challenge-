#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &arr, int &k)
{
    //    Write your code here.
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[i]>dq.back())
          dq.pop_back();
        dq.push_back(arr[i]);
    }
    ans.push_back(dq.front());

    for(int i=k;i<arr.size();i++)
    {
        if(dq.front()==arr[i-k])
          dq.pop_front();
        while(!dq.empty() && arr[i]>dq.back())
          dq.pop_back();
        dq.push_back(arr[i]);
        ans.push_back(dq.front());
    }
    return ans;
}
