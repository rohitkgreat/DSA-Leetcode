class Solution {
public:
    
    void helper(int node,vector<int> g[],vector<int> &ans,vector<bool> &vis,unordered_map<int,int> mp,bool &f)
    {
        mp[node]++;
        vis[node]=1;
        
        for(auto z:g[node])
           { if(mp.find(z)!=mp.end())
            {
                f=true;       
            }
            if(vis[z]==0)
                helper(z,g,ans,vis,mp,f);}
        if(f==false)
        ans.push_back(node);
        else
            return;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> g[numCourses];
        int z=pre.size();
        
        unordered_map<int,int> mp;
        bool f=false;
        for(int i=0;i<z;i++)
        {
           g[pre[i][0]].push_back(pre[i][1]);
        }
        vector<bool> vis(numCourses,0);
        vector<int> ans;
        
        for(int i=0;i<numCourses;i++)
        {
            mp.clear();
            if(vis[i]==0)
                helper(i,g,ans,vis,mp,f);
        }
        
        if(ans.size()!=numCourses)
            ans.clear();
        return ans;
    }
};