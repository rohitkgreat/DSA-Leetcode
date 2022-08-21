class Solution {
public:
    int helper(int i,int j,vector<int> &cuts,int **dp)
    {
        if(i>j)
            return 0;
        int mini=INT_MAX;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int z=i;z<=j;z++)
        {
            int cur=cuts[j+1]-cuts[i-1]+helper(i,z-1,cuts,dp)+helper(z+1,j,cuts,dp);
            mini=min(mini,cur);
            
        }
        
        return dp[i][j]=mini;
        
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        int **dp=new int*[c+2];
        for(int i=0;i<=c+1;i++)
        {
            dp[i]=new int[c+2];
            for(int j=0;j<=c+1;j++)
                dp[i][j]=0;
        }
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j)continue;
                
                int mini=INT_MAX;
        
                for(int z=i;z<=j;z++)
                {
                    int cur=cuts[j+1]-cuts[i-1]+dp[i][z-1]+dp[z+1][j];
                    mini=min(mini,cur);

                }
                dp[i][j]=mini;
        
            }
        }
        
        return dp[1][c];
        
        
        
        // return helper(1,c,cuts,dp);
    }
};