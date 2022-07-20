class Solution {
public:
    int helper(int r1,int c1,int r2, int c2,vector<vector<int>>& grid, vector<vector<vector<vector<int>>>> &dp)
    {
        if(r1>=grid.size() || c1>=grid[0].size() || r2>=grid.size() || c2>=grid[0].size())
            return -10000;
        
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -10000;
        
        if(dp[r1][c1][r2][c2]!=-1)
            return dp[r1][c1][r2][c2];
        if(r1==grid.size()-1 && c1==grid[0].size()-1)
            return grid[r1][c1];
        
        int ans=0;
        
        if(r1==r2 && c1==c2)
            ans+=grid[r1][c1];
        else
            ans+=grid[r1][c1]+grid[r2][c2];
        
        int m1=helper(r1+1,c1,r2+1,c2,grid,dp);
        int m2=helper(r1+1,c1,r2,c2+1,grid,dp);
        int m3=helper(r1,c1+1,r2,c2+1,grid,dp);
        int m4=helper(r1,c1+1,r2+1,c2,grid,dp);
        
        ans+=max(m1,max(m2,max(m3,m4)));
        dp[r1][c1][r2][c2]=ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        vector<vector<vector<vector<int>>>> dp(n,(vector<vector<vector<int>>> (n,vector<vector<int>>(n,vector<int>(n,-1)))));
        
        int x= helper(0,0,0,0,grid,dp);
        if(x<1)
            return 0;
        
        return x;
    }
};