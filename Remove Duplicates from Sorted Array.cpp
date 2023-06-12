#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int cnt=0;
	for(int i=0;i<n;)
	{
		int j=i;
		cnt++;
		while(j<n && arr[i]==arr[j])
		  j++;
		i=j;
	}
	return cnt;
}
