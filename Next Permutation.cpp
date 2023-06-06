#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    //  Write your code here.
    int breakpt=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(p[i]<p[i+1])
        {
            breakpt=i;
            break;
        }
    }

    if(breakpt==-1)
    {
        reverse(p.begin(),p.end());
        return p;
    }
    
    for(int i=n-1;i>breakpt;i--)
    {
        if(p[i]>p[breakpt])
        {
            swap(p[i],p[breakpt]);
            break;
        }
          
    }

    sort(p.begin()+breakpt+1,p.end());
    return p;

}