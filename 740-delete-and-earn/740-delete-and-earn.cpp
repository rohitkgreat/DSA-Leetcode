class Solution {
public:
    int helper(int i,vector<int>& nums,int *dp)
    {
        if(i>=nums.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=INT_MIN;
        int count=0;
        
        int j=i;
        for(;j<nums.size();j++)
        {
            if(nums[i]==nums[j])
                count++;
            else if(nums[j]==(nums[i]+1))
                continue;
            else
                break;
        }
        ans=helper(j,nums,dp)+nums[i]*count;
        ans=max(ans,helper(i+1,nums,dp));
        
        dp[i]=ans;
        return ans;
    }
    int deleteAndEarn(vector<int>& nums) {
      
        int n=nums.size();
        int *dp=new int[n];
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
            dp[i]=-1;
        return helper(0,nums,dp);
    }
};