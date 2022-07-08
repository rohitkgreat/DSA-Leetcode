class Solution {
public:
    
    int helper(vector<int> &nums,int target,int *dp)
    {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans+=helper(nums,target-nums[i],dp);            
        }
        dp[target]=ans;
        return ans;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> temp;
        int ans=0;        
        int *dp=new int[target+5];
        
        for(int i=0;i<target+5;i++)
            dp[i]=-1;    
        return helper(nums,target,dp);
                
    }
};