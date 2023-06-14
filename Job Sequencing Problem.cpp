#include <bits/stdc++.h> 

static bool comparator(vector<int> a,vector<int> b)
{
    if(a[1]<b[1])  return true;
    if(a[1]>b[1])  return false;
    if(a[0]<b[0])  return true;
    return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    for(int i=0;i<n;i++)
      jobs[i].push_back(i+1);
    sort(jobs.begin(),jobs.end(),comparator); //sorting jobs  based on profit..
    reverse(jobs.begin(),jobs.end());//after reversing jobs will be in the order of decreasing profit

    int ans=0;
    int maxdeadline=0;
    for(auto it:jobs)
      maxdeadline=max(maxdeadline,it[0]);
    
    vector<int> arr(maxdeadline+1,-1);
    for(int i=0;i<n;i++)
    {
        if(arr[jobs[i][0]]==-1)
        {
            ans+=jobs[i][1];
            arr[jobs[i][0]]=jobs[i][2];
        }
          
        else
        {
            bool flag=false;
            int j=jobs[i][0];
            while(j>0)
            {
                if(arr[j]==-1)
                {
                    flag=true;
                    break;
                }
                j--;
            }
            if(flag)
            {
                ans+=jobs[i][1];
                arr[j]=jobs[i][2];
            }
        }
    }
    return ans;
}
