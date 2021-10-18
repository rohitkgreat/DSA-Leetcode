class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();
        int i=0,j=0,l=n-1;
        
        while(j<=l)
        {
            if(nums[j]==0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==1)
                j++;
            else
            {
                swap(nums[j],nums[l]);
                l--;
            }
        }
        
    }
};