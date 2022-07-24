class Solution {
public:
    int helper(int i,int target,vector<int> &nums)
    {
        if(i==nums.size() && target==0)
            return 1;
        if(i>=nums.size())
            return 0;
        
        int cnt1,cnt2;
        cnt1=helper(i+1,target-nums[i],nums);
        cnt2=helper(i+1,target+nums[i],nums);
        return cnt1+cnt2;
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(0,target,nums);
    }
};