void dfs(int x,vector<bool> &vis, vector<int> adj[])
{

    vis[x]=true;
    for(auto j:adj[x])
        if(vis[j]==false)
            dfs(j,vis,adj);
}


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int z=connections.size();
        vector<int> adj[n];
        
        vector<bool> vis(n,false);
        
        for(int i=0;i<z;i++)
        {
            int start=connections[i][0];
            int end=connections[i][1];
            
            adj[start].push_back(end);
            adj[end].push_back(start);
            
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
                dfs(i,vis,adj),count++;
        }
        
        if(count==1)
            return 0;
        else
        {
           if(z>=n-1)
               return count-1;
            else
                return -1;
        }
    }
};