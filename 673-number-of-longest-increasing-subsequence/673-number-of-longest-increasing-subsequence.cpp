class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        
        vector<int> dp(n,1);
        vector<int> hs(n,1);
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                   
                    if(dp[i]==dp[j]+1)
                        {hs[i]+=hs[j];}
                    else if(dp[j]+1>dp[i])
                        {dp[i]=max(dp[i],1+dp[j]);
                        hs[i]=hs[j];
                        }
                }
            }
            mx=max(mx,dp[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(dp[i]==mx)
            {
               cnt=cnt+hs[i];
            }
        
        return cnt;
    }
};
