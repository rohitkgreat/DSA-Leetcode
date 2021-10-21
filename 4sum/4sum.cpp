class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int>> ans;
         set<vector<int>> s;
        
        for(int i=0;i<n;i++)
        {
            int target1=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                int fnl=target1-nums[j];
                int start=j+1;
                int end=n-1;
                
                while(start<end)
                {
                    int twosum=nums[start]+nums[end];
                    if(twosum==fnl)
                    {  
                        vector<int> s1;
                        s1.push_back(nums[i]);
                        s1.push_back(nums[j]);
                        s1.push_back(nums[start]);
                        s1.push_back(nums[end]);
                            
                        s.insert(s1);
                        // ans.push_back(s1);
                        start++;
                        end--;
                            
                        
                    }
                    else if(twosum<fnl)
                        start++;
                    else
                        end--;
                }
            }
        }
       
        for(auto x:s)
            ans.push_back(x);
        // s.push_back(ans);
        
        
        return ans;
    }
};