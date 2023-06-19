#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	priority_queue<pair<int,pair<int,int>>> pq;
	for(int i=0;i<n;i++)
	{
		pq.push({a[i]+b[0],{i,0}});
	}

	vector<int> ans;
	while(k)
	{
		int sum=pq.top().first;
		int i=pq.top().second.first;
		int j=pq.top().second.second;
		pq.pop();
		ans.push_back(sum);
		pq.push({a[i]+b[j+1],{i,j+1}});
		k--;
	}
	return ans;
}
