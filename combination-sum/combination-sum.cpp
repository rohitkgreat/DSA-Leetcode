class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        // int n=candidates.size();
        set<vector<int>> s;
        vector<int> temp;
        int i=0;
            
        helper(candidates,target,temp,s,i);
        
        for(auto x:s)
            ans.push_back(x);
        
        return ans;
        
    }
    void helper(vector<int>& candidates, int target,vector<int> temp,set<vector<int>> &s,int i)
    {
        if(i==candidates.size()){
     
            if(target==0)
        {
            sort(temp.begin(),temp.end());
            s.insert(temp);
            temp.clear();
                
        }
                return;
        
        }
        
        if(target-candidates[i]>=0)
        {
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],temp,s,i);
             temp.pop_back();
        }
        // if(!temp.empty())
           
        
        helper(candidates,target,temp,s,i+1);
        
        return;
    }
};