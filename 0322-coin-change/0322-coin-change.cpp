class Solution {
public:
    long long helper(int i,vector<int> &coins,int amount,int **dp)
    {
        if(amount==0)
            return 0;
        if(i>=coins.size())return INT_MAX;
        
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        
        long long ans=INT_MAX;
        
        for(int z=i;z<coins.size();z++)
        {
            if(amount-coins[z]>=0)
            {
                long long cur=1+helper(z,coins,amount-coins[z],dp);
                ans=min(ans,cur);
            }
        }
        ans=min(ans,helper(i+1,coins,amount,dp));
        return dp[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[amount+1];
            for(int j=0;j<=amount;j++)
                dp[i][j]=-1;
        }
        int z= helper(0,coins,amount,dp);
        if(z==INT_MAX)
            return -1;
        return z;
    }
};