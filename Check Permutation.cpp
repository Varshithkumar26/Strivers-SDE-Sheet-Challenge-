#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    vector<int> cnt1(26,0),cnt2(26,0);
    for(auto it:str1)
      cnt1[it-'a']++;
    for(auto it:str2)
      cnt2[it-'a']++;

    for(int i=0;i<26;i++)
    {
        if(cnt1[i]!=cnt2[i])
          return false;
    }
    return true;
}
