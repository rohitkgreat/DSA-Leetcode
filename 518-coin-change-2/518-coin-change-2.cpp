class Solution {
public:
    int helper(int pos,int amt,vector<int>& coins,int **dp)
    {
        if(pos>=coins.size() || amt<0)
            return 0;
        if(dp[amt][pos]!=-1)
           return dp[amt][pos];
        if(amt==0)
            return 1;
      
        int ans=0;
        
        for(int i=pos;i<coins.size();i++)
        {
           ans+=helper(i,amt-coins[i],coins,dp);
           
        }
        dp[amt][pos]=ans;
        return ans;
    }
    
    int change(int amount, vector<int>& coins) {
        int **dp=new int*[amount+1];
        for(int i=0;i<amount+1;i++)
        {
            dp[i]=new int[coins.size()];
            for(int j=0;j<coins.size();j++)
                dp[i][j]=-1;
        }
            
        
        return helper(0,amount,coins,dp);
    }
};