class Solution {
public:
    vector<int> tmp{-1,0,1};
    // tmp.push_back(-1);
    // tmp.push_back(0);
    // tmp.push_back(1);
    int helper(int row,int col1,int col2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp)
    {
        if(col1<0 || col2<0 || col1>=grid[0].size() || col2>=grid[0].size())
            return -1000000;
        if(row==grid.size()-1)
        {
            if(col1==col2)
                return grid[row][col1];
            else
                return grid[row][col1]+grid[row][col2];
        }
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        int mx=-1;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int val=0;
                if(col1==col2)
                    val=grid[row][col1];
                    // mx=max(mx,+helper(row+1,col1+tmp[i],col2+tmp[j],grid));
                else
                    val=grid[row][col1]+grid[row][col2];
                // mx=max(mx,+);
                val+=helper(row+1,col1+tmp[i],col2+tmp[j],grid,dp);
                mx=max(mx,val);
                
            }
        }
        dp[row][col1][col2]=mx;
        return mx;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
     return helper(0,0,grid[0].size()-1,grid,dp);   
    }
};