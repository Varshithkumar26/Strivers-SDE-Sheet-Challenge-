int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int flips=0;
    int ans=0;
    int i=0,j=0;
    while(i<n)
    {
        if(arr[i]==0)
          flips++;
        
        while(flips>k)
        {
            if(arr[j++]==0)
              flips--;
        }
        ans=max(ans,i-j+1);
        i++;
    }

    return ans;
}
