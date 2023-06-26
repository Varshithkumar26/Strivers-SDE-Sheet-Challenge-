#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> right(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--) // to find next smaller element(to the right)
    {
        while(!st.empty() && a[st.top()]>=a[i])
          st.pop();
        if(st.empty())
          right[i]=n;
        else
          right[i]=st.top();
        st.push(i);
    }

    vector<int> left(n);
    stack<int> st1;
    for(int i=0;i<n;i++)// to find prev smaller element(to the left)
    {
        while(!st1.empty() && a[st1.top()]>=a[i])
          st1.pop();
        if(st1.empty())
          left[i]=-1;
        else
          left[i]=st1.top();
        st1.push(i);
    }

    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++)
    {
        int length=right[i]-left[i]-1;
        ans[length-1]=max(a[i],ans[length-1]);
    }

    for(int i=n-2;i>=0;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }

    return ans;
}
