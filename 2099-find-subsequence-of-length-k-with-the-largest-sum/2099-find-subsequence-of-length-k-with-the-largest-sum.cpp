class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> dum;
        for(int i=0;i<n;i++)
        {
            dum.push_back({nums[i],i});
        }
        sort(dum.begin(),dum.end());
        
        vector<pair<int,int>> tmp;
        
        for(int i=n-k;i<n;i++)
            tmp.push_back({dum[i].second,dum[i].first});
        
        sort(tmp.begin(),tmp.end());
        vector<int> ans;
        
        for(auto z:tmp)
            ans.push_back(z.second);
        
        
        return ans;
    }
};