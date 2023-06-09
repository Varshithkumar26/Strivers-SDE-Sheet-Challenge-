#include <bits/stdc++.h>

int uniquePaths(int m, int n) {
  // Write your code here.

  // ans=(m+n-2)C(n-1)
  int a = m + n - 2;
  int b = n - 1;
  long long ans = 1;
  for (int i = 1; i <= b; i++)
     ans=ans*(a-b+i)/i;
  
  return (int)ans;
}
