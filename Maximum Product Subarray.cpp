#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int ans=INT_MIN;
	int prefix=1,suffix=1;
	for(int i=0;i<n;i++)
	{
		if(suffix==0)
		  suffix=1;
		if(prefix==0)
		  prefix=1;
		suffix*=arr[i];
		prefix*=arr[n-i-1];
		ans=max({ans,prefix,suffix});
	}
	return ans;
	
}
