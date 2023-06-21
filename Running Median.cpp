#include<bits/stdc++.h>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;
    maxheap.push(arr[0]);
    int l=1,r=0;
    if(n>0)
     cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
        if(arr[i]<maxheap.top())
        {
            maxheap.push(arr[i]);
            l++;
        }
        else
        {
            minheap.push(arr[i]);
            r++;
        }
        
        if(l-r>1)
        {
            int a=maxheap.top();
            maxheap.pop();
            l--;
            minheap.push(a);
            r++;
        }
        else if(l-r<0)
        {
            int a=minheap.top();
            minheap.pop();
            r--;
            maxheap.push(a);
            l++;
        }

        if(l==r)
          cout<<(minheap.top()+maxheap.top())/2<<" ";
        else 
          cout<<maxheap.top()<<" ";
        
    }
}
