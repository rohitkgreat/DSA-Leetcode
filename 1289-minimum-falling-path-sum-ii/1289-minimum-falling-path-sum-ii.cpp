class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& grid,int **dp)
    {
        if(row==grid.size())
        return 0;
        
        if(dp[row][col]!=100000)
            return dp[row][col];
        int ans=INT_MAX;
        for(int i=0;i<grid[0].size();i++)
        {
            if(i!=col)
            ans=min(ans,helper(row+1,i,grid,dp)+grid[row][i]);
            
        }
        dp[row][col]=ans;
        return ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        int **dp=new int*[row];
        
        for(int i=0;i<row;i++)
        {
            dp[i]=new int[col];
            for(int j=0;j<col;j++)
                dp[i][j]=100000;
        }
        int ans=INT_MAX;
        
        for(int i=0;i<col;i++)
            ans=min(ans,helper(1,i,grid,dp)+grid[0][i]);
        
        return ans;
    }
};