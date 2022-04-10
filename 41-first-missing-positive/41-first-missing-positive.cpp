class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int mx=INT_MIN;
        int mn=INT_MAX;
        
        unordered_map<int,int> mp;
        
        for(auto z:nums)
        {
            mp[z]++;     
            mx=max(mx,z);
            mn=min(mn,z);
        }
        
        int l=nums.size();
        
        for(int i=1;i<mx;i++)
        {
            
            if(mp.find(i)==mp.end())
            return i;
                
            
        }
        
        if(mx>0)
        return mx+1;
        
        return 1;
    }
};