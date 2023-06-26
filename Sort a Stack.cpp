#include <bits/stdc++.h> 

void insertinorder(stack<int> &st,int a)
{
	if(st.empty())
	{
		st.push(a);
		return;
	}

	if(st.top()<a)
	{
		st.push(a);
		return;
	}
	  
	int t=st.top();
	st.pop();
	insertinorder(st,a);
	st.push(t);
}

void f(stack<int> &st)
{
	if(st.empty())
	  return;
	
	int a=st.top();
	st.pop();
	f(st);
	insertinorder(st,a);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	f(stack);
}
