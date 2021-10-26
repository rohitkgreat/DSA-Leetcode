class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best=0;
        int cur=0,n=nums.size();
        
        int i=0,j=0;
        
        while(j<n)
        {
            if(nums[j]==1)
                cur++;
            else if(nums[j]==0)
            {
                cur=0;
                i=j+1;
            }
            best=max(cur,best);
            j++;
            
        }
        
        return best;
    }
};