class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<pair<int,int>,int>mp;
        
        int x=dig.size();
        for(int i=0;i<x;i++)
        {
            mp.insert({{dig[i][0],dig[i][1]},1});
        }
        int ans=0;
        int n1=artifacts.size();
        for(int i=0;i<n1;i++)
        {
            int x=artifacts[i][0];
            int y=artifacts[i][1];
            int x2=artifacts[i][2];
            int y2=artifacts[i][3];
            
            bool mila=true;
           
            for(int k=x;k<=x2;k++)
            {
                for(int m=y;m<=y2;m++){
                if(mp.find({k,m})==mp.end())
                {
                    mila=false;
                    break;
                }
                }
                
            }
            
            
            if(mila)
              { 
                ans++;
              }
        }
        
        
        return ans;
    }
};