#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int> ans;
	unordered_map<int,int> mp;
    for(int i=0;i<k;i++)
      mp[arr[i]]++;
    ans.push_back(mp.size());
    for(int i=k;i<arr.size();i++)
    {
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0)
          mp.erase(arr[i-k]);
        mp[arr[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}
