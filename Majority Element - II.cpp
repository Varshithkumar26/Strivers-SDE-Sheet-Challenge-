#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
    int n=nums.size();
    vector<int> ans;
    int ele1,ele2;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && nums[i]!=ele2)
        {
            ele1=nums[i];
            cnt1++;
        }
        else if(cnt2==0 && nums[i]!=ele1)
        {
            ele2=nums[i];
            cnt2++;
        }
        else if(nums[i]==ele1)
          cnt1++;
        else if(nums[i]==ele2)
          cnt2++;
        else
          cnt1--,cnt2--;
    }

    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==ele1)
          c1++;
        if(nums[i]==ele2)
          c2++;
    }

    if(c1>n/3)
      ans.push_back(ele1);
    if(c2>n/3)
      ans.push_back(ele2);

    sort(ans.begin(),ans.end());
    return ans;

}
