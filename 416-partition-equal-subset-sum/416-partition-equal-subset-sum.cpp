class Solution {
public:
    bool helper(int i,int tar,vector<int>& nums,int **dp)
    {
        if(i>=nums.size() || tar<0)
            return false;
        if(tar==0)
            return true;
        
        if(dp[i][tar]!=-1)
            return dp[i][tar];
        
        dp[i][tar]=helper(i+1,tar-nums[i],nums,dp) || helper(i+1,tar,nums,dp);
        return dp[i][tar];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        
        if(sum%2!=0)
            return false;
        // cout<<sum;
        int n=nums.size();
        int **dp=new int*[n];
        sum=sum/2;
        
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[sum+1];
            for(int j=0;j<=sum;j++)
                dp[i][j]=-1;
        }
        return helper(0,sum,nums,dp);
    }
};