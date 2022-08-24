class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      
        int des=-1;
        int n=nums.size();
        int i=0;
        
        while(i<n-1)
        {
            if(des==-1)
            {
                if(nums[i]==nums[i+1])
                    {i++;
                    continue;}
                if(nums[i]>nums[i+1])
                    des=1;
                else
                    des=0;
            }
            else if(des==0)
            {
                if(nums[i]>nums[i+1])
                    return false;
            }
            else
            {
                if(nums[i+1]>nums[i])
                    return false;
            }
            i++;
        }
        return true;
        
    }
};