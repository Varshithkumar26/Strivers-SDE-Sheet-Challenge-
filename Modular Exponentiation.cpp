#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long ans=1;
	long long val=x;
    while(n)
	{
		if(n%2)
		{
			ans=(ans%m*val%m)%m;
		}
		val=(val%m*val%m)%m;
		n=n>>1;
	}

	return (int)ans%m;
	
}
