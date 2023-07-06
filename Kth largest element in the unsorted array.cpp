#include <bits/stdc++.h> 

int partition(vector<int>& arr,int low,int high)
{
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j)
    {
        while(i<high && pivot>=arr[i])
          i++;
        while(j>low && pivot<arr[j])
          j--;
        if(i<j)
         swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

int QuickSelect(vector<int>& arr,int low,int high,int k)
{
    if(low>=high)
      return arr[low];
    
    int pindex=partition(arr,low,high);
	if(pindex+1==k)
	{
		return arr[pindex];
	}
	if(pindex+1>k)
      return QuickSelect(arr,low,pindex-1,k);
	else
      return QuickSelect(arr,pindex+1,high,k);
}
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	return QuickSelect(arr,0,size-1,size-K+1);
}
