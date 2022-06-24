class Solution {
public:
    bool helper(vector<int>& nums,int i,int *dp)
    {
        if(i==nums.size()-1)
            return true;
        if(i>=nums.size())
            return false;
        if(nums[i]==0)
            return false;
        
        if(dp[i]!=-1)
            return dp[i];
        bool ans=false;
        for(int j=1;j<=nums[i];j++)
        {
            ans=helper(nums,j+i,dp);
            if(ans)
           {
                dp[i]=ans;
                return ans;
            }
        }
        dp[i]=false;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        return helper(nums,0,dp);
    }
};