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
        
        if(sum%2!=0 || nums.size()==1)
            return false;
        // cout<<sum;
        int n=nums.size();
        int **dp=new int*[n];
        sum=sum/2;
        
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[sum+1];
            for(int j=0;j<=sum;j++)
                {dp[i][j]=0;
                dp[i][0]=1;}
            
        }
        if(nums[0]>sum)
            return false;
        dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++)
            for(int j=1;j<=sum;j++)
            {
                if(nums[i]>sum)
                    return false;
                bool a=false;
                if(j>=nums[i])
                a=dp[i-1][j-nums[i]];
                bool b=dp[i-1][j];
                
                dp[i][j]=a||b;
            }
        // return helper(0,sum,nums,dp);
        return dp[n-1][sum];
    }
};