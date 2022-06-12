class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       
        unordered_map<int,int> mp;
        int n=nums.size();
        
        int cur=0,ans=INT_MIN;
        
        int i=0,j=0;
        while(j<n)
        {
            cur+=nums[j];
            if(mp.find(nums[j])!=mp.end())
            {
                cur-=nums[j];
                ans=max(ans,cur);
                while(mp.find(nums[j])!=mp.end())
                {
                    cur-=nums[i];
                    mp.erase(nums[i]);
                    i++;
                }
                cur+=nums[j];
            }
            
            mp[nums[j]]++;
            j++;
        }
        
        
        ans=max(ans,cur);
        
        return ans;
    }
};