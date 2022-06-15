class Solution {
public:
//     int helper(int i,int n,vector<int>& nums,int *dp)
//     {
//         if(i>=n)
//             return 0;
//         if(dp[i]!=-1)
//             return dp[i];
//         int first=-1,second=-1;
//         if(i!=n-1)
//         first=helper(i+2,n,nums,dp)+nums[i];
        
//         second=helper(i+1,n,nums,dp);
        
//         dp[i]= max(first,second);
//         return dp[i];
    // }
    int helper2(int i,int n,vector<int>& nums,int *dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        dp[i]=max(helper2(i+2,n,nums,dp)+nums[i],helper2(i+1,n,nums,dp));
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        if(n==1)
            return nums[0];
        
        int ans1=helper2(0,n-1,nums,dp);
        for(int i=0;i<n;i++)
            dp[i]=-1;
        
        int ans2=helper2(1,n,nums,dp);
    
        return max(ans1,ans2);
        // ans=max(ans,nums[n-1]);
        // return ans;
    }
};