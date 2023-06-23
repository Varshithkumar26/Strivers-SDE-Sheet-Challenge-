 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & arr) {
   // Write your code here.
    int n=arr.size();
    vector<int> left(n);
    stack<int> s1;
    for(int i=0;i<n;i++)
    {
      while(!s1.empty() && arr[i]<=arr[s1.top()])
        s1.pop();
      
      if(s1.empty())
        left[i]=-1;
      else
        left[i]=s1.top();
      s1.push(i);
    }

    vector<int> right(n);
    stack<int> s2;
    for(int i=n-1;i>=0;i--)
    {
      while(!s2.empty() && arr[i]<=arr[s2.top()])
        s2.pop();
      
      if(s2.empty())
        right[i]=-1;
      else
        right[i]=s2.top();
      s2.push(i);
    }


    int ans=0;
    for(int i=0;i<n;i++)
    {
      if(right[i]==-1)
        right[i]=n;
      ans=max(ans,(right[i]-left[i]-1)*arr[i]);
    }
    return ans;
 }
