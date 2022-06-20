class Solution {
public:
    int helper(int i,vector<int>& cost,int *dp)
    {
        if(i>=cost.size())
            return 0;
        if(i==cost.size()-1)
            return cost[i];
        
        if(dp[i]!=-1)
            return dp[i];
        int first=helper(i+1,cost,dp)+cost[i];
        
        int second=helper(i+2,cost,dp)+cost[i];
        
        dp[i]=min(first,second);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
      
        int n=cost.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
            return min(helper(0,cost,dp),helper(1,cost,dp));
            
        
    }
};