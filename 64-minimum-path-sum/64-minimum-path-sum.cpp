class Solution {
public:
    
    int helper(int row,int col,int n,int m,vector<vector<int>>& grid,int **dp)
    {
        if(row==n-1 && col==m-1)
            return grid[row][col];
        if(row>=n || col>=m)
            return INT_MAX;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int right=helper(row,col+1,n,m,grid,dp);
        int down=helper(row+1,col,n,m,grid,dp);
        
        dp[row][col]=min(right,down)+grid[row][col];
        return dp[row][col];    
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        int **dp=new int*[row];
        
        for(int i=0;i<row;i++)
        {
            dp[i]=new int[col];
            for(int j=0;j<col;j++)
                dp[i][j]=-1;
        }
        
        return helper(0,0,row,col,grid,dp);
        
        
    }
};