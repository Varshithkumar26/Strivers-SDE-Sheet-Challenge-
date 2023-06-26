string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.length();
    int ans=0,fidx;
    for(int i=0;i<n;i++)
    {
        int p1=i,p2=i;
        while(p1>=0 && p2<n)
        {
            if(str[p1]==str[p2])
            {
                if(ans<p2-p1+1)
                {
                    ans=p2-p1+1;
                    fidx=p1;
                }
                p1--;
                p2++;
            }
            else
              break;
        }
    }

    for(int i=0;i<n;i++)
    {
        int p1=i,p2=i+1;
        while(p1>=0 && p2<n)
        {
            if(str[p1]==str[p2])
            {
                if(ans<p2-p1+1)
                {
                    ans=p2-p1+1;
                    fidx=p1;
                }
                p1--;
                p2++;
            }
            else
              break;
        }
    }

    return str.substr(fidx,ans);
}
