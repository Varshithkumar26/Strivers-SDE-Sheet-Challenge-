#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int cnt=0;
    vector<int> a={1,2,5,10,20,50,100,500,1000};
    while(amount>0)
    {
        cnt++;
        int idx=upper_bound(a.begin(),a.end(),amount)-a.begin();
        amount-=a[idx-1];
    }

    return cnt;
}
