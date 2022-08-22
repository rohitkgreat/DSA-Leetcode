class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int i=0;
        int mid;
        while(i<=n)
        {
            mid=(i+n)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                n=mid-1;
            else
                i=mid+1;
        }
        
        if(nums[mid]>target)
            return mid;
        
        return mid+1;
    }
};