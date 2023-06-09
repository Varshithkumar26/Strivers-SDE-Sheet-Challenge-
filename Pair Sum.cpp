#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   unordered_map<int,int> mp;
   for(auto it:arr)
   {
      if(mp.find(s-it)!=mp.end())
      {
         for(int i=0;i<mp[s-it];i++)
         {
            if(it>(s-it))
              ans.push_back({s-it,it});
            else
              ans.push_back({it,s-it});
         }
      }
      mp[it]++;
   }

   sort(ans.begin(),ans.end());
   return ans;
}
