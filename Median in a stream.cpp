#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> ans;
	priority_queue<int> max;
	priority_queue<int,vector<int>,greater<int>> min;
	int l=0,r=0;
	for(int i=0;i<n;i++)
	{
		if(l==0 || arr[i]<=max.top())
		{
			max.push(arr[i]);
			l++;
		}
		else
		{
			min.push(arr[i]);
			r++;
		}
		if(l-r>1)
		{
			int t=max.top();
			max.pop();
			l--;
			min.push(t);
			r++;
		}
		if(l<r)
		{
			int t=min.top();
			min.pop();
			r--;
			max.push(t);
			l++;
		}
		int median;
		if(l==r)
		  median=(max.top()+min.top())/2;
		else 
		  median=max.top();
		ans.push_back(median);
	}
	return ans;
}
