#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.

	//MOORE'S VOTING ALGORITHM
	int cnt=0;
	int ele;
	for(int i=0;i<n;i++)
	{	
		if(cnt==0)
		  ele=arr[i];
		if(arr[i]==ele)
		  cnt++;
		else
		  cnt--;
	}

	int c=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==ele)
		  c++;
	}
	if(c>n/2)
	  return ele;
	return -1;
}
