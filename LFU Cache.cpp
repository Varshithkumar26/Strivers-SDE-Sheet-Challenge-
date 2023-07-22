#include <bits/stdc++.h> 
class LFUCache
{
public:
    unordered_map<int,int> mp;
    int n;
    LFUCache(int capacity)
    {
        // Write your code here.
        mp.clear();
        n=capacity;
    }

    int get(int key)
    {
        // Write your code here.
        if(mp.find(key)==mp.end())
        return -1;
        return mp[key];

    }

    void put(int key, int value)
    {
        // Write your code here.
        if(mp.find(key)!=mp.end())
        mp[key]=value;
        else if(n>mp.size())
        {
            mp[key]=value;
            
        }
        else
        {
            int mini=INT_MAX;
            int mikey=INT_MAX;
            for(auto x: mp)
            {
                if(x.second<mini)
                {
                    mini=x.second;
                    mikey=x.first;
                }
            }
            mp.erase(mikey);
            mp[key]=value;
        }
    }
};
