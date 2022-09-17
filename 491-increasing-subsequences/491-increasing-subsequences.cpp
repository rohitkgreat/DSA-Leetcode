class Solution {
public:
    void helper(int idx,int cur,vector<int>& nums,set<vector<int>> &ans,vector<int> temp)
    {
        if(temp.size()>1)
        {
            ans.insert(temp);            
        }
        if(idx>=nums.size())
            return;
        
        if(cur==-101)
        {
            temp.push_back(nums[idx]);
            helper(idx+1,nums[idx],nums,ans,temp);
            temp.pop_back();
            // helper(idx+1,cur,nums,ans,temp);
        }
        if(nums[idx]>=cur)
        {
            temp.push_back(nums[idx]);
            helper(idx+1,nums[idx],nums,ans,temp);
            temp.pop_back();
            // helper(idx+1,cur,nums,ans,temp);
        }
        helper(idx+1,cur,nums,ans,temp);
        
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        helper(0,-101,nums,ans,temp);
        vector<vector<int>> ans1;
        
        for(auto z:ans)
            ans1.push_back(z);
        return ans1;
    }
};