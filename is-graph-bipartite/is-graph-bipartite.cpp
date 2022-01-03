class Solution {
public:
    
    bool helper(vector<vector<int>>& graph,vector<int> col,int i)
    {
        queue<int> q;
        q.push(i);
        col[i]=1;
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            
            for(auto z:graph[x])
            {   
             if(col[z]==-1)
               {
                    col[z]=1-col[x];
                    q.push(z);
                    
                }
                // for(auto a:col)
                //     cout<<a<<" ";
                if(col[z]==col[x])
                    return false;
                
            }
          
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            if(!helper(graph,col,i))
                return false;
        }
        
        return true;
       
    }
};