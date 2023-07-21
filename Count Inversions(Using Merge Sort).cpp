#include <bits/stdc++.h> 
int merge(long long *arr,int low,int mid,int high)
{
    int cnt=0;
    int left=low,right=mid+1;
    vector<int> a;
    while(left<=mid && right<=high)
    {
        if(arr[left]>arr[right])
        {
            cnt+=mid-left+1;
            a.push_back(arr[right++]);
        }
        else
         a.push_back(arr[left++]); 
    }
    
    while(left<=mid)
      a.push_back(arr[left++]);
    
    while(right<=high)
      a.push_back(arr[right++]);
      
    for(int i=low;i<=high;i++)
      arr[i]=a[i-low];
    
    return cnt;
}

int mergesort(long long *arr,int low,int high)
{
    if(low>=high)
      return 0;
    
    int cnt=0;  
    int mid=(low+high)/2;
    cnt+=mergesort(arr,low,mid);
    cnt+=mergesort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergesort(arr,0,n-1);
}
