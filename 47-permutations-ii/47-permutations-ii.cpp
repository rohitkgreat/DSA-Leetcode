class Solution {
public:
    void helper(vector<int>& nums,vector<int> temp,set<vector<int>> &ans,int arr[])
    {
        if(temp.size()==nums.size())
        {
            ans.insert(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(arr[i]==0)
            {
                arr[i]=1;
                temp.push_back(nums[i]);
                helper(nums,temp,ans,arr);
                temp.pop_back();
                arr[i]=0;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        int n=nums.size();
        int arr[n+1];
        
        for(int i=0;i<n;i++)
            arr[i]=0;
        
        vector<int> temp;
        
        helper(nums,temp,ans,arr);
        vector<vector<int>> anss;
        
        for(auto z:ans)
            anss.push_back(z);
        
        return anss;
        
    }
};