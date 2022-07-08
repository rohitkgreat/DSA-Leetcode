class Solution {
public:
    
    void helper(int z,vector<vector<int>> &ans,vector<int> &temp,int n,int k,int sum)
    {
        
        if(sum==n && temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k || sum>n)
            return;
        
        
        for(int i=z;i<=9;i++)
        {
            temp.push_back(i);
            helper(i+1,ans,temp,n,k,sum+i);         
            temp.pop_back();
         
        }
        
        return;
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<bool>vis(10,0);
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1,ans,temp,n,k,0);
        
        return ans;
    }
};