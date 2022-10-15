class Solution {
public:
    void helper(vector<int> temp,vector<int>& nums,set<vector<int>>&s,vector<int>& vis)
    {
        if(temp.size()==nums.size())
        {
            s.insert(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                temp.push_back(nums[i]);
                helper(temp,nums,s,vis);
                vis[i]=0;
                temp.pop_back();
            }
        }
        return;
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        int n=nums.size();
        vector<int> vis(n,0);
        vector<int> temp;
        helper(temp,nums,s,vis);
        
        vector<vector<int>> ans;
        for(auto z:s)
            ans.push_back(z);
        
        return ans;
    }
};