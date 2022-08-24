class Solution {
public:
    void helper(int row,int col,vector<vector<int>> &grid,bool &flag,int &cnt)
    {
        // cout<<row<<" "<<col<<endl;
        if(row<0 || row>=grid.size()|| col<0 || col>=grid[0].size())
        {
            flag=true;
            return;
        }
        if(grid[row][col]==0)
            return;
        cnt++;
        grid[row][col]=0;
        helper(row+1,col,grid,flag,cnt);
        helper(row-1,col,grid,flag,cnt);
        helper(row,col+1,grid,flag,cnt);
        helper(row,col-1,grid,flag,cnt);
        
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        cout<<row<<" "<<col;
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // cout<<row<<" "<<col<<endl;
                if(grid[i][j]==1)
                {   
                    int cnt=0;
                    bool flag=false;
                    helper(i,j,grid,flag,cnt);
                    if(flag==false)
                        ans+=cnt;
                }
            }
        }
        return ans;
    }
};