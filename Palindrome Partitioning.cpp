#include <bits/stdc++.h> 

bool isvalid(string a)
{
    int n=a.length();
    int p1=0,p2=n-1;
    while(p1<=p2)
    {
        if(a[p1++]!=a[p2--])
          return false;
    }
    return true;
}

void f(int idx,string &s,vector<string>&ds,vector<vector<string>>&ans)
{
    if(idx==s.length())
    {
        ans.push_back(ds);
        return;
    }

    string a;
    for(int i=idx;i<s.length();i++)
    {
        a+=s[i];
        if(isvalid(a))
        {
            ds.push_back(a);
            f(i+1,s,ds,ans);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> ds;
    vector<vector<string>> ans;
    f(0,s,ds,ans);
    return ans;
}
