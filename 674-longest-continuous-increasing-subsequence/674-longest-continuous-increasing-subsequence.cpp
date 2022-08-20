class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx=1;
        int curmx=1;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
                curmx++;
            else
            {
                curmx=1;
            }
            mx=max(mx,curmx);
        }
        return mx;
    }
};