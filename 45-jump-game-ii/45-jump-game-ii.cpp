class Solution {
public:
    int helper(vector<int>& nums,int i,int *dp)
    {
        if(i==nums.size()-1)
            return 0;
        if(i>=nums.size())
            return 1000000;
        if(nums[i]==0)
            return 1000000;
        
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
         int x=1+helper(nums,i+j,dp);
         ans=min(ans,x);
         // return min(x,ans);   
        }
        dp[i]=ans;
        return ans;
        // return 0;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        int *dp=new int[n];
        
        for(int i=0;i<n;i++)
            dp[i]=-1;
        
        return helper(nums,0,dp);
    }
};