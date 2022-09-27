class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size();
        if(j==1)
            return 0;
        if(j==2)
            return nums[0]>nums[1]?0:1;
        j=j-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(nums[mid]>nums[mid+1])
                j=mid;
            else
                i=mid+1;
          
        }
        return i;
    }
};