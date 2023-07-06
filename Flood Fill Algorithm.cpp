#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int m=image.size(),n=image[0].size();
    int color=image[x][y];
    if(color==newColor)
      return image;
    vector<vector<int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
    queue<pair<int,int>> q;
    q.push({x,y});
    image[x][y]=newColor;
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto it:dir)
            {
                int row=r+it[0];
                int col=c+it[1];
                if(row>=0 && row<m && col>=0 && col<n && image[row][col]==color)
                {
                    q.push({row,col});  
                    image[row][col]=newColor; 
                }            
            }
        }
    }
    return image;
}
