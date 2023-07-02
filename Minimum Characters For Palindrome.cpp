#include<bits/stdc++.h>
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.length();
	int a=n-1;
	int p1=0,p2=n-1;
	int ans=0;
	while(p1<=p2)
	{
		if(str[p1]==str[p2])
		{
			p1++;
			p2--;
		}
		else
		{
			ans++;
			p1=0;
			a--;
			p2=a;
		}
	}
	return ans;
	
}
