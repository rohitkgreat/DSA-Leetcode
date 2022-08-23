class Solution {
public:
    bool helper(int row,int col,vector<vector<int>> &grid,int **dp)
    {
        
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
            return false;
        
        if(grid[row][col]==1)
            return true;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        dp[row][col]=1;
        
        bool up=helper(row-1,col,grid,dp);
        bool down=helper(row+1,col,grid,dp);
        bool left=helper(row,col-1,grid,dp);
        bool right=helper(row,col+1,grid,dp);
        
        dp[row][col]=(up && down && left && right);
        return dp[row][col];
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int row,col;
        row=grid.size();
        col=grid[0].size();
        int **dp=new int*[row+1];
        for(int i=0;i<=row;i++)
        {
            dp[i]=new int[col+1];
            for(int j=0;j<=col;j++)
                dp[i][j]=-1;
        }
        int cnt=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0 && dp[i][j]==-1)
                {
                    // cout<<i<<" "<<j<<dp[i][j]<<endl;
                    if(helper(i,j,grid,dp))
                    {
                        
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};