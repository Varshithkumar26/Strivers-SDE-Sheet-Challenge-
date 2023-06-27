string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans=arr[0];
    for(int i=1;i<n;i++)
    {
        string prefix;
        int p1=0,p2=0;
        while(p1<arr[i].length() && p2<ans.length() && arr[i][p1]==ans[p2])
        {
            prefix+=arr[i][p1];
            p1++;
            p2++;
        }
        ans=prefix;
    }
    return ans;
}


