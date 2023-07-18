int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
     vector<vector<int>> adjmatrix(n+1,vector<int>(n+1,1e9));
     for(int i=1;i<=n;i++)
       adjmatrix[i][i]=0;
     for(auto it:edges)
       adjmatrix[it[0]][it[1]]=it[2];

     for(int via=1;via<=n;via++)
     {
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 if(adjmatrix[i][via]!=1e9 && adjmatrix[via][j]!=1e9)
                 {
                     adjmatrix[i][j]=min(adjmatrix[i][j],adjmatrix[i][via]+adjmatrix[via][j]);
                 }
             }
         }
     }

     return adjmatrix[src][dest];
}
