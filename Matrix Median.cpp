#include<bits/stdc++.h>

int ceil(vector<int> &mat,int ele)
{
    int low=0,high=mat.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(mat[mid]>ele)
          high=mid-1;
        else
          low=mid+1;
    }
    return low;
}

int count(vector<vector<int>> &matrix,int ele)
{
    int cnt=0;
    for(int i=0;i<matrix.size();i++)
    {
        //int idx=upper_bound(matrix[i].begin(),matrix[i].end(),ele)-matrix[i].begin();
        int idx=ceil(matrix[i],ele);
        cnt+=idx;
    }
    return cnt;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size(),m=matrix[0].size();
    int low=1,high=1e9;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(count(matrix,mid)<=(n*m/2))
          low=mid+1;
        else
          high=mid-1;
    }
    return low;
}
