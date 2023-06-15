#include<bits/stdc++.h>
#include<bits/stdc++.h>

bool isvalid(int row,int col,int matrix[9][9],int val)
{
    int r=0,c=0;
    while(r<9)
    {
        if(matrix[r++][col]==val)
          return false;
    }
    while(c<9)
    {
        if(matrix[row][c++]==val)
          return false;
    }

    int i=0;
    while(i<9)
    {
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==val)
          return false; 
        i++;
    }

    return true;
}

bool solve(int matrix[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(isvalid(i,j,matrix,k))
                    {
                        matrix[i][j]=k;
                        if(solve(matrix))
                          return true;    
                        matrix[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
    
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    return solve(matrix);

    
}
