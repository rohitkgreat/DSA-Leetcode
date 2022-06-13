class Solution {
public:
    
    int helper(int row,int col,int n,int m,int **dp,vector<vector<int>>& obstacleGrid)
    {
       if(row>=n || col>=m)
            return 0;
        
        if(obstacleGrid[row][col]==1)
         return 0;
        if(row==n-1 && col==m-1)
            return 1;

        if(dp[col][row]!=-1)
            return dp[col][row];
     
        
        int right=helper(row,col+1,n,m,dp,obstacleGrid);
        int down=helper(row+1,col,n,m,dp,obstacleGrid);
        
        
        dp[col][row]=right+down;
        return  dp[col][row];
        
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();  //4
        int m=obstacleGrid[0].size(); //3
        
        int **dp=new int*[m];
        
        for(int i=0;i<m;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }
        
        return helper(0,0,n,m,dp,obstacleGrid);
    }
};