#include <bits/stdc++.h> 

int merge(vector<int> &arr,int low,int mid,int high)
{
    int cnt=0;
    int left=low,right=mid+1;
    vector<int> a;

	while(left<=mid)
	{
		while(right<=high && arr[left]>2*arr[right])
		  right++;
		cnt+=(right-mid-1);
		left++;
	}

	left=low,right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]>arr[right])
         a.push_back(arr[right++]);
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

int mergesort(vector<int> &arr,int low,int high)
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

int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return mergesort(arr,0,n-1);	
}
