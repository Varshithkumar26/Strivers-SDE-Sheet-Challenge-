int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
      arr.push_back({at[i],0});
    for(int i=0;i<n;i++)
      arr.push_back({dt[i],1});

    sort(arr.begin(),arr.end());
    int ans=0;
    int cnt=0;
    for(auto it:arr)
    {
        if(it.second==1)
          cnt--;
        else 
          cnt++;
        ans=max(ans,cnt);
    }
    return ans;
}
