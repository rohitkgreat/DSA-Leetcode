class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int target=-nums[i];
            int start=i+1;
            int end=n-1;
            
            while(start<end)
            {
                int sum=nums[start]+nums[end];
                if(sum<target)
                    start++;
                else if(sum>target)
                    end--;
                else
                {
                    vector<int> temp={nums[i],nums[start],nums[end]};
                    ans.push_back(temp);
                    
                    while(start<end && nums[start]==temp[1])
                        start++;
                    while(start<end && nums[end]==temp[2])
                        end--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            
        }
        
        return ans;
        
    }
};