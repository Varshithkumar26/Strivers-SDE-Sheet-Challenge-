#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
    // Write your code here.
    vector<vector<long long int>> ans;
    for(int i=1;i<=n;i++)
    {
        vector<long long> row;
        row.push_back(1);
        long long res=1;
        for(int j=1;j<i;j++)
        {
           res=res*(i-j);
           res=res/j;
           row.push_back(res);
        }
        ans.push_back(row);
    }
    return ans;
}
