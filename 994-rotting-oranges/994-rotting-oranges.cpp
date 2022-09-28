class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==2)
                    {q.push({i,j});
                     grid[i][j]=3;
                    }
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int z=x+dx[i];
                    int a=y+dy[i];
                    
                    if(z<0 || a<0 || z>=row || a>=col)
                        continue;
                    else
                    {
                        if(grid[z][a]==1)
                        {
                            grid[z][a]=3;
                            q.push({z,a});
                        }
                    }
                }
                
            }
            if(q.size())
            ans++;
        }
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==1)
                    return -1;
        return ans;
    }
};