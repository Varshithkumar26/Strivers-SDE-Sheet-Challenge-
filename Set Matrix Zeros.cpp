#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int m=matrix.size(),n=matrix[0].size();
	unordered_set<int> row,col;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]==0)
			{
				row.insert(i);
				col.insert(j);
			}
		}
	}

	for(auto it:row)
	{
		for(int i=0;i<n;i++)
		  matrix[it][i]=0;
	}

	for(auto it:col)
	{
		for(int i=0;i<m;i++)
		  matrix[i][it]=0;
	}


}
