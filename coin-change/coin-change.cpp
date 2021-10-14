long long check(vector<int>& coins,int dp[],int n,int size )
{
    if(n==0)
        return 0;
    
    if(dp[n]!=0)
        return dp[n];
    
    long long ans=INT_MAX;
    
    for(int i=0;i<size;i++)
    {
        if(n-coins[i]>=0)
        {
            long long sub=1+check(coins,dp,n-coins[i],size);
            ans=min(ans,sub);
        }
    }
    dp[n]=ans;
    return dp[n];
}




class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int x=amount+1;
       
        int dp[10001]={0};
        // int *dp=new int[x];
        int z= check(coins,dp,amount,n);
        if(z==INT_MAX)
            return -1;
        return z;
    }
};