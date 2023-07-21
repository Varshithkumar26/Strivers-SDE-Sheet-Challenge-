#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	
	// res=(m+n-2)C(m-1)
	int res=1;
	for(int i=1;i<m;i++)
	{
		res*=(m+n-1-i);
		res=res/i;
	}

	return res;
}
