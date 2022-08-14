class Solution {
public:
    bool helper(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i>=nums.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        if(i+1<nums.size() && nums[i]==nums[i+1])
        {
            if(helper(i+2,nums,dp))
            {
                dp[i]=1;
                return true;
            }
            if(i+2<nums.size() && nums[i]==nums[i+2])
                if(helper(i+3,nums,dp))
                {dp[i]=true;
                    return true;}
        }
        
       if(i+2<nums.size() && nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2)
            if(helper(i+3,nums,dp))
            {dp[i]=true; 
                return true;
            }
                
        return dp[i]= false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return helper(0,nums,dp);
    }
};