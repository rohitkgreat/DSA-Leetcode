class Solution {
public:
    int helper(int n,int k,int target,int **dp)
    {
        if(n==0 && target==0)
            {
            return 1;
            }
        if(n==0 || target<0 )
            return 0;
            
        if(dp[n][target]!=-1)
            return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;i++)
        {
           (ans)=(ans+helper(n-1,k,target-i,dp))%1000000007;
            // helper(n,i,target,count);
        }
        dp[n][target]=ans;
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[target+1];
            for(int j=0;j<=target;j++)
            {
                dp[i][j]=-1;
            }
        }
//         if(n==1 && target<=k)
//             return 1;
//         if(n==1 && target>k)
//             return 0;
        
        return helper(n,k,target,dp);
        
    }
};