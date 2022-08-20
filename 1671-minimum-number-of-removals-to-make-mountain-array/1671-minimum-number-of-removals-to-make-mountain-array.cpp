class Solution {
public:
    void helper(vector<int>&nums,vector<int> &dp)
    {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }

    }
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dpf(n,1);
        vector<int> dpb(n,1);
        helper(nums,dpf);
        reverse(nums.begin(),nums.end());
        helper(nums,dpb);
        reverse(dpb.begin(),dpb.end());
        
        int mx=-1;
        for(int i=0;i<n;i++)
        {
           if(dpf[i]==1 || dpb[i]==1)
               continue;
            
            mx=max(mx,dpf[i]+dpb[i]-1);
        }
        return nums.size()-mx;
        
    }
};