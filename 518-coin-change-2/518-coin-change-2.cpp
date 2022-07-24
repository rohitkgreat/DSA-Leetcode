class Solution {
public:
    int helper(int i,int target,vector<int> &coins,int **dp)
    {
        if(target==0)
            return 1;
        if(i>=coins.size() || target<0)
            return 0;
        if(dp[i][target]!=-1)
            return dp[i][target];
        
        int x=helper(i+1,target,coins,dp);
        int y=helper(i,target-coins[i],coins,dp);
        
        dp[i][target]=x+y;
        return x+y;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int **dp=new int*[n];
        
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[amount+1];
            for(int j=0;j<=amount;j++)
                dp[i][j]=-1;
            
        }
        
        return helper(0,amount,coins,dp);
    }
};