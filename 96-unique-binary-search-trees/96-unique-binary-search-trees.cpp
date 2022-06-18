class Solution {
public:
    
    int helper(int n,int *dp)
    {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        int ans=0;
        for(int i=0;i<n;i++)
        {
           int left=helper(i,dp);
           int right=helper(n-i-1,dp);
           ans+=left*right; 
        }
        dp[n]=ans;
        return ans;
    }
    int numTrees(int n) {
        int *dp=new int[n+1];
        
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        
        return helper(n,dp);
    }
};