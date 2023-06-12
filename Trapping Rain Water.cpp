#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int p1=0,p2=n-1;
    long leftmax=arr[p1],rightmax=arr[p2];
    long ans=0;
    while(p1<p2)
    {
        if(arr[p1]<arr[p2])
        {
            p1++;
            leftmax=max(leftmax,arr[p1]);
            ans+=1l*leftmax-1l*arr[p1];
        }
        else
        {
            p2--;
            rightmax=max(rightmax,arr[p2]);
            ans+=1l*rightmax-1l*arr[p2];
        }
    }

    return ans;


}
