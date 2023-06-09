#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<int,int> mp;
    for(auto it:arr)
      mp[it]++;
    
    int ans=1;
    for(auto it:arr)
    {
        if(mp.find(it-1)!=mp.end())
          continue;
        else
        {
            int a=it;
            int cnt=1;
            while(mp.find(a+1)!=mp.end())
            {
                a++;
                cnt++;
            }
            ans=max(ans,cnt);
        }
    }

    return ans;

}
