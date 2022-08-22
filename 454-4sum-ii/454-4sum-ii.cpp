class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp;
        
        int n=nums2.size();
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                mp[sum]++;
            }
        
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int sum=nums3[i]+nums4[j];
                sum=-1*sum;
                ans+=mp[sum];
            }
        
        return ans;
    }
};