class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
     
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        int z=operations.size();
        
        for(int i=0;i<z;i++)
        {
            if(mp2.find(operations[i][0])==mp2.end())
            {
                mp.insert({operations[i][0],operations[i][1]});
                mp2.insert({operations[i][1],operations[i][0]});
                
            }
            else
            {
                mp[mp2[operations[i][0]]]=operations[i][1];
                mp2.insert({operations[i][1],mp2[operations[i][0]]});
                mp2.erase(operations[i][0]);
            }
            
        }
        cout<<mp2[3]<<"*";
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
                nums[i]=mp[nums[i]];
        }
        
        return nums;
    }
};