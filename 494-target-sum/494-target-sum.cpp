class Solution {
public:
    int helper(int i,int target,vector<int> &nums)
    {
        if(i==nums.size() && target==0)
            return 1;
        if(i>=nums.size())
            return 0;
        // if(dp[i][target]!=-1)
        //     return dp[i][target];
        
        return helper(i+1,target-nums[i],nums)+helper(i+1,target+nums[i],nums);
        // return dp[i][target];
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // int **dp=new int*[n+1];
        
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i]=new int[target+1];
        //     for(int j=0;j<=target;j++)
        //         dp[i][j]=-1;
        // }
        return helper(0,target,nums);
    }
};