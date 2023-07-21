#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int m1=row1.size(),n1=row2.size();
    if(m1>n1)
      return ninjaAndLadoos(row2,row1,n1,m1,k);
    int low=max(0,k-n1),high=min(k,m1);
    while(low<=high)
    {
        int cut1=(low+high)/2;
        int cut2=k-cut1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(cut1>0)
          l1=row1[cut1-1];
        if(cut2>0)
          l2=row2[cut2-1];
        if(cut1<m1)
          r1=row1[cut1];
        if(cut2<n1)
          r2=row2[cut2];
        if(l1<=r2 && l2<=r1)
          return max(l1,l2);
        if(l1>r2)
          high=cut1-1;
        else
          low=cut1+1;
    }
    return 0;

}
