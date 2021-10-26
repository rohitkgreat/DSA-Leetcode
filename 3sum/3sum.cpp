class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
         set<vector<int>> s;
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
        int n=nums.size();
        unordered_map<int,int> mp;
        if(n==0 || nums[0]>0)
            return ans;
        
        
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]>0)
                continue;
            mp[nums[i]]++;
            int k=i+1,j=n-1;
            while(k<j)
            {
                if(nums[i]+nums[k]+nums[j]==0)
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[j]);
                    
                    s.insert(temp);
                    j--;
                    k++;
                }
                else if(nums[i]+nums[k]+nums[j]>0)
                    j--;
                else
                    k++;
            }
        }
       
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
};