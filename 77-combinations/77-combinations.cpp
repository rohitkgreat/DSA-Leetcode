class Solution {
public:
    void helper(int i,int n,int k,vector<int>&temp,vector<vector<int>> &ans)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        if(i==n+1)
            return;
        temp.push_back(i);
        helper(i+1,n,k,temp,ans);
        temp.pop_back();
        helper(i+1,n,k,temp,ans);
        
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(1,n,k,temp,ans);
        
        return ans;
    }
};