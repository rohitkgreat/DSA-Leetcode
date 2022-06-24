class Solution {
public:
    int helper(vector<vector<int>>& grid,int row,int col,int **vis,int obst,int cell)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
            return 0;
        if(grid[row][col]==2 )
        {
            // cout<<obst<<" ";
            if(obst>=cell)
            return 1;
            
            return 0;
        }
        if(vis[row][col]==1)
            return 0;
        if(grid[row][col]==-1)
             return 0;
        
        
         vis[row][col]=1;
        
        int up=helper(grid,row-1,col,vis,obst+1,cell);
        int left=helper(grid,row,col-1,vis,obst+1,cell);
        int down=helper(grid,row+1,col,vis,obst+1,cell);
        int right=helper(grid,row,col+1,vis,obst+1,cell);
  
        vis[row][col]=0;
        
        return up+left+down+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int obst=1;
        int **vis=new int*[row];
        int cell=row*col;
        for(int i=0;i<row;i++)
        {
            vis[i]=new int[col];
            for(int j=0;j<col;j++)
           {    if(grid[i][j]==-1)
                 obst++;
            
                vis[i][j]=0;
            }
        }

          for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    return helper(grid,i,j,vis,obst,cell);
                }
            }
        }
        
        return 0;
    }
};