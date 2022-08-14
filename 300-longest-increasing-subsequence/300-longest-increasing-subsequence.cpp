class Solution {
public:
    
    int helper(int idx,int cur,vector<int> &nums,int **dp)
    {
        if(idx>=nums.size())
            return 0;
       
        if(cur==-1)
            return max(1+helper(idx+1,idx,nums,dp),helper(idx+1,cur,nums,dp));
        
        if(cur!=-1 && dp[idx][cur]!=-1)
            return dp[idx][cur];
        
        if(nums[idx]>nums[cur])
            return dp[idx][cur]= max(1+helper(idx+1,idx,nums,dp),helper(idx+1,cur,nums,dp));
        
        return dp[idx][cur]=helper(idx+1,cur,nums,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        return helper(0,-1,nums,dp);
    }
};