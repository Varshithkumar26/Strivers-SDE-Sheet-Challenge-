#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n-2;i++)
	{
		if(i!=0 && arr[i]==arr[i-1])
		  continue;
		int j=i+1,k=n-1;
		while(j<k)
		{
			int sum=arr[i]+arr[j]+arr[k];
			if(sum==K)
			{
				ans.push_back({arr[i],arr[j],arr[k]});
				while(j<k && arr[j]==arr[j+1])
				  j++;
				while(j<k && arr[k]==arr[k-1])
				  k--;
			
				j++;
				k--;
			}
			else if(sum<K)
			{
				while(j<k && arr[j]==arr[j+1])  //this while loop is not req,works even if its removed
				  j++;
				j++;
			}
			else
			{
				while(j<k && arr[k]==arr[k-1])  //this while loop is not req,works even if its removed
				  k--;
				k--;
			}
		}
	}
	return ans;
}
