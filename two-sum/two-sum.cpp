class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        int n=nums.size();
        int i=0,j=n-1;
        vector<pair<int,int>> v;
       
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        while(i<j)
        {   int a=v[i].first;
            int b=v[j].first;
            if(a+b==target)
            {
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                break;
                
            }
            else if(a+b>target)
                j--;
            else
                i++;
        }
        
        return ans;
    }
};