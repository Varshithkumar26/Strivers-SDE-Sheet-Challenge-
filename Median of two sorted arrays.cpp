#include<bits/stdc++.h>

double median(vector<int>& a, vector<int>& b) {

	// Write your code here.
	int n=a.size(),m=b.size();
	if(m<n)
	  return median(b,a);//always do BS on smaller array
	
	int low=0,high=(n+m+1)/2;
	while(low<=high)
	{
		int cut1=(low+high)/2;//denotes the no of ele from first array
		int cut2=(n+m+1)/2-cut1;
		int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
		if(cut1>0)
		  l1=a[cut1-1];//a[cut1-1]/l1 denoted the last ele from first array on left side
		if(cut2>0)
		  l2=b[cut2-1];
		if(cut1<n)
		  r1=a[cut1];//a[cut1]/r1 denoted the first ele from first array on right side
		if(cut2<m)
		  r2=b[cut2];
		
		if(l1<=r2 && l2<=r1)
		{
			if((n+m)%2!=0)
			  return max(l1,l2);
			else
			  return ((max(l1,l2)+min(r1,r2)))/2.0;
		}
		else if(l1>r2)//we need to dec l1 so we need to decrease cut1
		  high=cut1-1;
		else
		  low=cut1+1;//r2 needs to be dec so cut1 is moved to right
	}

	return 0.0;
	
}
