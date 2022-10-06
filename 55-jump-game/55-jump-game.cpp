class Solution {
public:
    bool helper(int i,vector<int>& nums,vector<int>& dp)
    {
        if(i==nums.size()-1)
            return true;
        if(i>=nums.size())
            return false;
        if(dp[i]!=-1)
            return dp[i];
        
        for(int z=1;z<=nums[i];z++)
        {
            bool ans=helper(i+z,nums,dp);
            if(ans)
                return dp[i]= true;
        }
        return dp[i]= false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return helper(0,nums,dp);
    }
};