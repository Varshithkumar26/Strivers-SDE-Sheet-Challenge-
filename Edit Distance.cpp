#include<bits/stdc++.h>

int f(int i,int j,string &str1, string &str2,vector<vector<int>> &dp)
{
    if(i==str1.length())
      return str2.length()-j;
    if(j==str2.length())
      return str1.length()-i;
    
    if(dp[i][j]!=-1)
      return dp[i][j];

    int ans;
    if(str1[i]==str2[j])
      ans=f(i+1,j+1,str1,str2,dp);
    else
    {
        int rep=1+f(i+1,j+1,str1,str2,dp);
        int insert=1+f(i,j+1,str1,str2,dp);
        int del=1+f(i+1,j,str1,str2,dp);

        ans=min({rep,insert,del});
    }

    return dp[i][j]=ans;
}

int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.length(),n=str2.length();
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // return f(0,0,str1,str2,dp);

    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++)
     dp[m][i]=n-i;
    for(int i=0;i<=m;i++)
     dp[i][n]=m-i;
    
    for(int i=m-1;i>=0;i--)
    {
      for(int j=n-1;j>=0;j--)
      {
        if(str1[i]==str2[j])
          dp[i][j]=f(i+1,j+1,str1,str2,dp);
        else
        {
            int rep=1+dp[i+1][j+1];
            int insert=1+dp[i][j+1];
            int del=1+dp[i+1][j];

            dp[i][j]=min({rep,insert,del});
        }
      }
    }

    return dp[0][0];
}
