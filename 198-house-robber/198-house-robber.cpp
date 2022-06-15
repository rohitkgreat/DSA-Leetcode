class Solution {
public:
    int helper(int i,int n,vector<int>& nums,int *dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=max(helper(i+2,n,nums,dp)+nums[i],helper(i+1,n,nums,dp));
        
        dp[i]= ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        return helper(0,n,nums,dp);
    }
};