class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i=0,n=nums.size();
        vector<vector<int>>ans;
        vector<int> temp;
        set<vector<int>> ans1;
        helper(nums,i,temp,n,ans1);
        
      for(auto x:ans1)
          ans.push_back(x);
        

        return ans;
    }
    void helper(vector<int>& nums,int i,vector<int> temp,int n,set<vector<int>> &ans)
    {
        if(i==n)
        {
         sort(temp.begin(),temp.end());
         ans.insert(temp);
         temp.clear();
         return;
        }
        temp.push_back(nums[i]);
        helper(nums,i+1,temp,n,ans);
        temp.pop_back();
        helper(nums,i+1,temp,n,ans);
        
        return;
            
    }
};