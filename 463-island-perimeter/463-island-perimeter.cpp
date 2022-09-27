class Solution {
public:
    void helper(int row,int col,vector<vector<int>> &grid,int &ans)
    {
        // cout<<row<<" "<<col<<endl;
        if(row>=grid.size() || col>=grid[0].size() || row<0 || col<0 || grid[row][col]==0)
        {
            ans++;
            return;
        }
        if(grid[row][col]==2)
            return;
        grid[row][col]=2;
        helper(row+1,col,grid,ans);
        helper(row-1,col,grid,ans);
        helper(row,col+1,grid,ans);
        helper(row,col-1,grid,ans);
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rw=grid.size();
        int cl=grid[0].size();
        int ans=0;
        for(int i=0;i<rw;i++)
            for(int j=0;j<cl;j++)
            {
                if(grid[i][j]==1)
                {
                    helper(i,j,grid,ans);
                    break;
                }
            }
        return ans;
    }
};