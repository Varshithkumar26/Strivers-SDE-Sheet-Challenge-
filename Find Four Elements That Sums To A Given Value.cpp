#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int sum=0;
    for(int i=0;i<n;)
    {
        for(int j=i+1;j<n;)
        {
            sum=target-arr[j]-arr[i];
            int k=j+1,l=n-1;
            while(k<l)
            {
                if(sum==(arr[k]+arr[l]))
                  return "Yes";
                if(sum<(arr[k]+arr[l]))
                {
                    while(k<l && arr[l]==arr[l-1])
                      l--;
                    l--;
                }
                else
                {
                    while(k<l && arr[k]==arr[k+1])
                      k++;
                    k++;   
                }
            }   
            while(j<n-1 && arr[j]==arr[j+1])
                j++;
            j++;       
        }
        while(i<n-1 && arr[i]==arr[i+1])
          i++;
        i++; 

    }

    return "No";
}
