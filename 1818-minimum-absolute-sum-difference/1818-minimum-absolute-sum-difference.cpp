class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums2.size();
        long long minsum=0;
         vector<int> nums=nums1;
        for(int i=0;i<n;i++)
        {
            minsum+=abs(nums1[i]-nums2[i]);
        }
        long long insum=minsum;
        // cout<<minsum<<" ";
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<n;i++)
        {
            int cur=abs(nums1[i]-nums2[i]);
            int start=0,end=n-1;
            
            while(start<=end)
            {
                int mid=(start+end)/2;
                if(nums[mid]>nums2[i])
                    {
                        
                        end=mid-1;
                        
                    }
                else
                {
                    start=mid+1;
                }
                minsum=min(minsum,insum-(cur-abs(nums[mid]-nums2[i])));
                        
            }
           // cout<<i<<minsum<<endl;
            
        }
        return minsum%1000000007;
    }
};