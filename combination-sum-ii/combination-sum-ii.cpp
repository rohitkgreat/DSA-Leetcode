class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        helper(candidates,target,temp,ans,0);
        
        return ans;
        
    }
    void helper(vector<int>& candidates, int target,vector<int> &temp,vector<vector<int>> &ans,int z)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
      
        for(int i=z;i<candidates.size();i++)
        {
            if(i>z && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],temp,ans,i+1);
            temp.pop_back();
        
        }
    }
};


// class Solution {
//     public: 
    // void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
    //     if(target==0) {
    //         ans.push_back(ds);
    //         return;
    //     }        
    //     for(int i = ind;i<arr.size();i++) {
    //         if(i>ind && arr[i]==arr[i-1]) continue; 
    //         if(arr[i]>target) break; 
    //         ds.push_back(arr[i]);
    //         findCombination(i+1, target - arr[i], arr, ans, ds); 
    //         ds.pop_back(); 
    //     }
    // }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans; 
//         vector<int> ds; 
//         findCombination(0, target, candidates, ans, ds); 
//         return ans; 
//     }
// };