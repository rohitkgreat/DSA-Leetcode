int check(int x,vector<int> parent)
{
    if(parent[x]==x)
        return x;
    else
        return check(parent[x],parent);
}


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
        
        int count=0;
       
        
        while(count<n)
        {
            vector<int>temp=edges[count];
            int s=temp[0];
            int e=temp[1];
            int src=check(s,parent);
            int dest=check(e,parent);
            
            if(src==dest)
                return temp;
            else
                parent[src]=dest;
            
            count++;
        }
        
        return edges[n];
        
    }
};