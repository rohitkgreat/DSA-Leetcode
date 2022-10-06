class Solution {
public:
    int helper(int i,int n,vector<int>& nums,vector<int> &dp){
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int x=nums[i]+helper(i+2,n,nums,dp);
        int y=0+helper(i+1,n,nums,dp);
        
        return dp[i]=max(x,y);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n+1,-1);
        int ans=helper(0,n-1,nums,dp);
        fill(dp.begin(),dp.end(),-1);
        return max(ans,helper(1,n,nums,dp));
    }
};