class Solution {
public:
   
    int helper(vector<int>& nums, int target,int i,bool used)
    {
       
        if(target==0 && i==nums.size())
            {
            return 1;
            }     
        
        
        if(i>=nums.size())
            return 0;
        
        int count=0;
        count+=helper(nums,target+nums[i],i+1,true);
        count+=helper(nums,target-nums[i],i+1,true);
        
        // cout<<i<<" "<<count<<"\n";
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        bool used=false;   
        return helper(nums,target,0,used);
    }
};