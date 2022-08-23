class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid1,int **vis)
    {
        if(row<0 || row>=grid1.size() || col<0 || col>=grid1[0].size() || grid1[row][col]!=1 || vis[row][col]==1)
            return;
        
        vis[row][col]=1;
        
        dfs(row-1,col,grid1,vis);
        dfs(row+1,col,grid1,vis);
        dfs(row,col-1,grid1,vis);
        dfs(row,col+1,grid1,vis);
    }
    bool check(int row,int col,vector<vector<int>>& grid2,int **vis,int **vis2)
    {
        
        if(row<0 || row>=grid2.size() || col<0 || col>=grid2[0].size() || vis2[row][col]==1 || grid2[row][col]==0)
            return true;
        // cout<<row<<" "<<col<<endl;
        if(vis[row][col]==0)
            {
            // cout<<row<<" "<<col<<endl;
            return false;}
        vis2[row][col]=1;
        bool up=check(row-1,col,grid2,vis,vis2);
        bool down=check(row+1,col,grid2,vis,vis2);
        bool right=check(row,col-1,grid2,vis,vis2);
        bool left=check(row,col+1,grid2,vis,vis2);
        
        return up&&down&&right&&left;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int row=grid1.size();
        int col=grid1[0].size();
        int **vis=new int*[row];
        for(int i=0;i<row;i++)
        {
            vis[i]=new int[col];
            for(int j=0;j<col;j++)
                vis[i][j]=0;
        }
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(grid1[i][j]==1 && vis[i][j]==0)
                    dfs(i,j,grid1,vis);
            }
        int **vis2=new int*[row];
        for(int i=0;i<row;i++)
        {
            vis2[i]=new int[col];
            for(int j=0;j<col;j++)
                vis2[i][j]=0;
        }
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid2[i][j]==1 && vis2[i][j]==0)
                {
                    if(check(i,j,grid2,vis,vis2))
                        ans++;
                }
            }
        }
        return ans;
    }
};