class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
            return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int mx=1;
        int idx;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<1+dp[j])
                    {
                        dp[i]=1+dp[j];
                        hash[i]=j;
                        
                    }
                }
            }
            if(mx<dp[i])
            {
                mx=dp[i];
                idx=i;
            }
        }
        // for(auto z:dp)
        //     cout<<z<<" ";
        vector<int> temp;
        temp.push_back(nums[idx]);         
        while(hash[idx]!=idx)
        {
            idx=hash[idx];
            temp.push_back(nums[idx]);         
        }
        reverse(temp.begin(),temp.end());
        
        return temp;
    }
};