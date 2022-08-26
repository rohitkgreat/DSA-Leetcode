class Solution {
public:
    int xc[4]={-1,1,0,0};
    int yc[4]={0,0,1,-1};
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        if(q.size()==row*col)
            return -1;
        
        int dist=0;
        while(!q.empty())
        {
            int z=q.size();
            dist++;
            
            while(z--)
            {  
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int newx=x+xc[i];
                    int newy=y+yc[i];
                    
                    if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==0)
                        {q.push({newx,newy});
                         grid[newx][newy]=1;
                        }
                }
                
            }
        }
        
        return dist-1;
    }
};