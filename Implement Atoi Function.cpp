#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int n=str.length();
    bool flag=true;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            flag=false;
            ans=ans*10+str[i]-'0';
        }
    }

    if(flag)
      return 0;
    if(str[0]=='-')
      return -ans;
    return ans;
}
