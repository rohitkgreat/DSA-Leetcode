class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<long long>> dp(row,vector<long long>(col));
        vector<vector<long long>> mn(row,vector<long long>(col));
        
        dp[0][0]=mn[0][0]=grid[0][0];
        for(int i=1;i<row;i++)
        {
            dp[i][0]=dp[i-1][0]*grid[i][0];
            mn[i][0]=dp[i][0];  
        }
        for(int i=1;i<col;i++)
        {
            dp[0][i]=dp[0][i-1]*grid[0][i];
            mn[0][i]=dp[0][i];
        }
        
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
            {
                if(grid[i][j]>=0)
                {
                    mn[i][j]=min(mn[i-1][j],mn[i][j-1])*grid[i][j];
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])*grid[i][j];
                }
                else
                {
                    mn[i][j]=max(dp[i-1][j],dp[i][j-1])*grid[i][j];
                    dp[i][j]=min(mn[i-1][j],mn[i][j-1])*grid[i][j];
                }
            }
        if(dp[row-1][col-1]<0)
            return -1;
        
       
        return dp[row-1][col-1]%1000000007;
    }
};