class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp.insert({nums[i],nums[i]});
        
        int z=mp.size();
       
        int i=0;
        for(auto x:mp)
        {
            nums[i]=x.first;
            i++;
        }
        
       
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int z=i+1;
//             while(nums[i]==nums[z])
//             {
//                 nums[z]=-101;
//                 z=z+1;
//             }
            
//         }
        
        return mp.size();
    }
};