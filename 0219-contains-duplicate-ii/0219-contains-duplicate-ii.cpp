class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
        if(k==0)
            return false;
        if(nums.size()==1)
            return false;
        unordered_map<int,int>mp;
        
        int i=0,j=0;
        int n=nums.size();
        
        while(j<n)
        {
            if(abs(i-j)<=k)
              {  
                mp[nums[j]]++;
                if(mp[nums[j]]>1)
                    return true;
            }
            else
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
                mp[nums[j]]++;
                if(mp[nums[j]]>1)
                    return true;
            }
        j++;
        }
        
        return false;
    }
};