int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int low=0,high=arr.size()-2;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==arr[mid^1])
		  low=mid+1;
		else
		  high=mid-1;
	}
	return arr[low];
}
