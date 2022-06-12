class Solution {
public:
    
    int helper(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& moveCost,int **dp)
    {
        if(row==grid.size()-1)
            return grid[row][col];
        
        int ans=INT_MAX;
        if(dp[row][col]!=-1)
            return dp[row][col];
        for(int j=0;j<grid[0].size();j++)
        {
            int temp=helper(row+1,j,grid,moveCost,dp)+moveCost[grid[row][col]][j]+grid[row][col];
            ans=min(ans,temp);
        }
        dp[row][col]=ans;
        return ans;
    }
    
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        int **dp=new int*[row];
        
        for(int i=0;i<row;i++)
        {
            dp[i]=new int [col];
            for(int j=0;j<col;j++)
                dp[i][j]=-1;
        }
        
        cout<<dp[row-1][col-1];
        
        int anss=INT_MAX;
        for(int i=0;i<grid[0].size();i++)
        {
            int ge=helper(0,i,grid,moveCost,dp);
            anss=min(anss,ge);
        }
        
        return anss;
        
    }
};