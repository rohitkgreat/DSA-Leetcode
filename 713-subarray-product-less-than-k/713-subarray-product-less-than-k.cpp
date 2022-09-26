class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n=nums.size();
        int ans=0;
        if(k<=1)
            return 0;
        int i=0,j=0;
        int pro=1;
        while(j<n)
        {
            pro=pro*nums[j];
            if(pro<k)
            {
                ans+=j-i+1;
                j++;
            }
            else
            {
                while(pro>=k)
                {
                    pro=pro/nums[i];
                    i++;
                }
                ans+=j-i+1;
                j++;
            }
            
        }
        return ans;
    }
};