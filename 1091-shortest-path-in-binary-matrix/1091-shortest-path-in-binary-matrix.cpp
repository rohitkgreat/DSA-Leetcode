class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dis (n, vector<int> (n, 1e9));
        
        queue<vector<int>> q;
        
        if(grid[0][0] == 0){
            q.push({0, 0, 0});
        }
        
        int delrow[] = {1, 0, -1, 0, -1, 1, 1, -1};
        int delcol[] = {0, -1, 0, 1, -1, 1, -1, 1};
        
        while(!q.empty()){
            
            int dist = q.front()[0];
            int x = q.front()[1];
            int y = q.front()[2];
            q.pop();
            
            if(x == n-1 and y == n-1){
                return dist+1;
            }
            
            for(int i=0; i<8; i++){
                
                int newx = x + delrow[i];
                int newy = y + delcol[i];
                
                if(newx > -1 and newy > -1 and newx < n and newy < n and grid[newx][newy] == 0 and dis[newx][newy] > dist + 1){
                    
                    dis[newx][newy] = dist + 1;
                    q.push({dist+1, newx, newy});
                    
                }
                
            }
            
        }
        return -1;
    }
};