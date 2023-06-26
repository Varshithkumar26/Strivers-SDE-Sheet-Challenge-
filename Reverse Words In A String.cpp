#include<bits/stdc++.h>
string reverseString(string &str){
	// Write your code here.	
	int n=str.length();
	stack<string> st;
	for(int i=0;i<n;i++)
	{
		string s;
		int j=i;
		while(j<n && str[j]!=' ')
		{
			s+=str[j];
			j++;
		}
		st.push(s);
		while(j<n && str[j]==' ')
		  j++;
		i=j-1;
	}

	string ans;
	while(!st.empty())
	{
		ans+=st.top();
		st.pop();
		ans+=" ";
	}

	ans.pop_back();
	return ans;
}
