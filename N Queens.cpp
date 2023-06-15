#include<bits/stdc++.h>

bool isvalid(vector<vector<int>> &arr,int row,int col,int n)
{
    int r=0,c=0;
    while(c<n)
    {
        if(c==col)
        {
            c++;
            continue;
        }
        if(arr[row][c]==1)
          return false;
        c++;
    }

    r=row,c=col;
    while(r>=0 && c>=0)
    {
        if(arr[r][c]==1)
          return false;
        r--,c--;
    }

    r=row,c=col;
    while(r<n && c>=0)
    {
        if(arr[r][c]==1)
          return false;
        r++,c--;
    }
    return true;
}

void solve(int col,int n,vector<vector<int>> &arr,vector<vector<int>> &ans)
{
    if(col==n)
    {
        vector<int> temp;
        for(auto it:arr)
        {
            for(int i=0;i<it.size();i++)
              temp.push_back(it[i]);
        }  
        ans.push_back(temp);
    }

    for(int i=0;i<n;i++)
    {
        if(isvalid(arr,i,col,n))
        {
            arr[i][col]=1;
            solve(col+1,n,arr,ans);
            arr[i][col]=0;
        }
    }

}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> arr(n,vector<int>(n,0));
    vector<vector<int>> ans;
    solve(0,n,arr,ans);
    return ans;
}
