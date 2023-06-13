#include <bits/stdc++.h> 
struct meeting{
    int s;
    int e;
    int pos;
};

bool comparator(struct meeting m1,struct meeting m2)
{
    if(m1.e<m2.e)  return true;
    else if(m1.e>m2.e)  return false;
    else if(m1.pos<m2.pos)  return true;
    else  return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++)
      meet[i].s=start[i],meet[i].e=end[i],meet[i].pos=i+1;
    
    sort(meet,meet+n,comparator);
    vector<int> ans;
    int endtime=meet[0].e;
    ans.push_back(meet[0].pos);
    for(int i=1;i<n;i++)
    {
        if(endtime<meet[i].s)
        {
            ans.push_back(meet[i].pos);
            endtime=meet[i].e;
        }
    }

    return ans;
}
