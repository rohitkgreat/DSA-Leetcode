class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n=groupSizes.size();
        
        map<int,vector<int>> mp;
        vector<vector<int>> v;
        
        for(int i=0;i<n;i++)
        {
            mp[groupSizes[i]].push_back(i);
            
            if(mp[groupSizes[i]].size()==groupSizes[i])
            {
             v.push_back(mp[groupSizes[i]]);
              mp[groupSizes[i]].clear();  
            }
        }
        return v;
        
        
    }
};