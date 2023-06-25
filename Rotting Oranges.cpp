#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int,pair<int,int>>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
              q.push({i,{j,0}});
        }
    }
    
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int ans=0;
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int row=q.front().first;
            int col=q.front().second.first;
            int time=q.front().second.second;
            q.pop();
            ans=max(ans,time);
            for(auto it:dir)
            {
                int nrow=row+it[0];
                int ncol=col+it[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
                {
                    grid[nrow][ncol]=0;
                    q.push({nrow,{ncol,time+1}});
                }

            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
              return -1;
        }
    }

    return ans;

}
