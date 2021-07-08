class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> in(n,0);
        vector<vector<bool>> check(n,vector<bool>(n,false));
        
        int z=roads.size();
        
        for(int i=0;i<z;i++)
        {
            int x=roads[i][0];
            int y=roads[i][1];
            
            in[x]++;
            in[y]++;
            
            check[x][y]=1;
            check[y][x]=1;
        }
        
        int sum,best=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                sum=in[i]+in[j];
                if(check[i][j]==1)
                    sum--;
                best=max(sum,best);
            }
        }
        
        return best;
    }
};