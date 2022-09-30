class Solution {
public:
    void dfs(int x,vector<bool> &vis,vector<int> adj[])
    {
        vis[x]=1;
        for(auto z:adj[x])
        {
            if(vis[z]==0)
                dfs(z,vis,adj);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(isConnected[i][j]==1)
                adj[i].push_back(j);
            }
        }
        vector<bool> vis(n,0);
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};