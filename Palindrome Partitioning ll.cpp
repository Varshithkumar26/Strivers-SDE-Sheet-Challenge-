#include <bits/stdc++.h> 

bool palindrome(string s)
{
    int p1=0,p2=s.length()-1;
    while(p1<=p2)
    {
        if(s[p1]!=s[p2])
          return false;
        p1++,p2--;
    }
    return true;
}

int f(int idx,string &str,vector<int> &dp)
{
    if(idx==str.length())
      return 0;
    
    if(dp[idx]!=-1)
      return dp[idx];

    int ans=1e9;
    string temp;
    for(int i=idx;i<str.length();i++)
    {
        temp+=str[i];
        if(palindrome(temp))
        {
            int cuts=1+f(i+1,str,dp);
            ans=min(ans,cuts);
        }
    }

    return dp[idx]=ans;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n=str.length();
    vector<int> dp(n,-1);
    return f(0,str,dp)-1;
}
