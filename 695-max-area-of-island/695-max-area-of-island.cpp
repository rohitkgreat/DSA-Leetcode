class Solution {
public:
    
    void helper(int row,int col,vector<vector<int>>& grid,int &temp)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
            return;
        
        if(grid[row][col]==0)
            return;
        if(grid[row][col]==2)
            return;
        if(grid[row][col]==1)
            {temp++;
            grid[row][col]=2;}
        
        helper(row+1,col,grid,temp);
        helper(row-1,col,grid,temp);
        helper(row,col+1,grid,temp);
        helper(row,col-1,grid,temp);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        int temp=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                   { 
                    helper(i,j,grid,temp);
                    ans=max(ans,temp);   
                    temp=0;
                }
                
            }
        }
        
        return ans;
    }
};