#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n=input.length();
    vector<int> cnt(26,0);
    int ans=1;
    int i=0,j=0;
    while(j<n && i<n )
    {
        if(cnt[input[j]-'a']==0)
        {
            ans=max(ans,j-i+1);
            cnt[input[j++]-'a']++;
        }
          
        else
        {       
            cnt[input[i++]-'a']--;
        }
    }

    return ans;
}
