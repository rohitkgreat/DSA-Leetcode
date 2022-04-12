class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
//         set<pair<int,int>> s;
        
//         int z=nums.size();
        
//         for(int i=0;i<z;i++)
//         {
//             for(int j=i+1;j<z;j++)
//             {
//                 if(nums[i]-nums[j]==k)
//                 {
//                     s.insert({nums[i],nums[j]});
//                 }
//                 else if(nums[j]-nums[i]==k)
//                     s.insert({nums[j],nums[i]});
//             }
//         }
        
//         return s.size();
        int count=0;
        
        unordered_map<int,int> mp;
        
        for(auto x:nums)
            mp[x]++;
        
        int z=nums.size();
        
        if(k==0)
        {
            for(auto s:mp)
            {
                if(s.second>1)
                {
                    count++;
                }
            }
        }
        else{
        for(auto m:mp)
        {
            
            if(mp.find(m.first+k)!=mp.end())
                count++;
                
        }
        }
        
        return count;
    }
};