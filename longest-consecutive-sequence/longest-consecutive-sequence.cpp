class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        int n=nums.size();
        if(n==0)
            return 0;
        for(auto x:nums)
            mp[x]++;
        
       int ans=1;
        for(int i=0;i<n;i++)
        {
             int j=1,count=1;
            while(mp.find(nums[i]-j)!=mp.end())
            {
                mp.erase(nums[i]-j);
                count++;
                j++;
            }
            j=1;
            while(mp.find(nums[i]+j)!=mp.end())
            {
                mp.erase(nums[i]-j);
                count++;
                j++;
            }
            
            ans=max(ans,count);
            
        }
        
        return ans;
    }
};