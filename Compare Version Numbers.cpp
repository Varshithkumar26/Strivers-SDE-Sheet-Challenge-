#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int n=a.length(),m=b.length();
        int p1=0,p2=0;
        while(p1<n && p2<m)
        {
            while(p1<n && a[p1]=='0')
                p1++;
            while(p2<n && b[p2]=='0')
                p2++;
        
            long long num1=0;
            while(p1<n && a[p1]!='.')
            {
                num1=num1*10+a[p1]-'0';
                p1++;
            }
            long long num2=0;
            while(p2<m && b[p2]!='.')
            {
                num2=num2*10+b[p2]-'0';
                p2++;
            }
            if(num1>num2)
              return 1;
            if(num1<num2)
              return -1;
            if(a[p1]=='.')
              p1++;
            if(b[p2]=='.')
              p2++;
        }
        if(p1<n)
        {
            while(p1<n)
            {
                if(a[p1]!='.' && a[p1]!='0')
                return 1;
                p1++;
            }
        }
        if(p2<m)
        {
            while(p2<m)
            {
                if(b[p2]!='.' && b[p2]!='0')
                return -1;
                p2++;
            }
        }
        return 0;
}
