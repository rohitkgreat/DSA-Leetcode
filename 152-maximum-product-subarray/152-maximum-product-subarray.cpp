class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int ans = nums[0],max_prod = nums[0],min_prod = nums[0]; // initialize max product,min product and answer
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) // if number is negative, we will swap max prod and min prod
                swap(max_prod,min_prod);
            max_prod = max(nums[i],max_prod*nums[i]); // find current max prod each time
            min_prod = min(nums[i],min_prod*nums[i]); // find current min prod each time
            ans = max(ans,max_prod); // store the maximum product each time
        }
        return ans;
    }
};