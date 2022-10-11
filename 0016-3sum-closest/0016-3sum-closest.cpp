class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int ans;
        int dif=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cur=nums[i];
            int start=i+1;
            int end=n-1;
            
            while(start<end)
            {
                if(cur+nums[start]+nums[end]==target)
                    return target;
                if(abs(cur+nums[start]+nums[end]-target)<dif)
                {
                    dif=abs(cur+nums[start]+nums[end]-target);
                    ans=cur+nums[start]+nums[end];
                    
                }
                if(cur+nums[start]+nums[end]>target)
                    end--;
                else
                    start++;
            }
            
        }
                 return ans;
    }
};