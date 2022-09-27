class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        int ans=INT_MAX;
        if(nums[low]<nums[high])
            return nums[low];
        while(low<=high)
        {
            mid=(low+high)/2;
           
            if(nums[mid]>nums[low] && nums[mid]<nums[high])
            {
                high=mid-1;
                
            }
            else if(nums[mid]<=nums[low] && nums[mid]<=nums[high])
               {high=mid-1;
                ans=min(ans,nums[mid]);
               }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};