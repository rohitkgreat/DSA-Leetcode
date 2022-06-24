class Solution {
public:
    
    int helper(vector<vector<int>>& grid,int row,int col,int **vis)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
            return 0;
        
        if(grid[row][col]==0)
            return 0;
        if(vis[row][col]==1)
            return 0;
        
        vis[row][col]=1;
        
        int up=helper(grid,row-1,col,vis)+grid[row][col];
        int left=helper(grid,row,col-1,vis)+grid[row][col];
        int down=helper(grid,row+1,col,vis)+grid[row][col];
        int right=helper(grid,row,col+1,vis)+grid[row][col];
  
        vis[row][col]=0;
        
        return max(up,max(left,max(down,right)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        int **vis=new int*[row];
        for(int i=0;i<row;i++)
        {
            vis[i]=new int[col];
            for(int j=0;j<col;j++)
                vis[i][j]=0;
        }
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]!=0)
                {
                    ans=max(helper(grid,i,j,vis),ans);
                    // cout<<ans;
                }
            }
        }
        return ans;
    }
};