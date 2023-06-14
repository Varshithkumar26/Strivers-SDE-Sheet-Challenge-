#include <bits/stdc++.h> 

void f(int idx,int target, vector<int> &arr,vector<int>&ds,vector<vector<int>>&ans)
{
	if(target==0)
	{
		ans.push_back(ds);
		return;
	}

	for(int i=idx;i<arr.size();i++)
	{
		if(arr[idx]>target)
		  break;
		if(i!=idx && arr[i]==arr[i-1])
		  continue;
		ds.push_back(arr[i]);
		f(i+1,target-arr[i],arr,ds,ans);
		ds.pop_back();
	}
	return;

}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    f(0,target,arr,ds,ans);
    return ans;
}
