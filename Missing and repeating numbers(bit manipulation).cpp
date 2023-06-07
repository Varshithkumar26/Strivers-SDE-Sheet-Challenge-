#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xr=0;
	for(int i=0;i<n;i++)
	  xr=xr^arr[i]^(i+1);
	
	int posn;
	for(int i=0;i<32;i++)
	{
		if(((xr>>i)&1)==1)
		{
			posn=i;
			break;
		}
	}

	int a=0,b=0;
	for(int i=0;i<n;i++)
	{
		if(((arr[i]>>posn)&1)==1)
		  a^=arr[i];
		else
		  b^=arr[i];
	}
    
	for(int i=1;i<=n;i++)
	{
		if(((i>>posn)&1)==1)
		  a^=i;
		else
		  b^=i;
	}

	for(auto it:arr)
	{
		if(it==a)
		  return {b,a};
	}

	return {a,b};

	
}
