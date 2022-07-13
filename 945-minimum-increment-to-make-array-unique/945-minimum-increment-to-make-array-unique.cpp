class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1] || nums[i]>nums[i+1])
            {
                ans+=nums[i]-nums[i+1]+1;
                nums[i+1]=nums[i]+1;
            }
        }
        
        return ans;
        
    }
};