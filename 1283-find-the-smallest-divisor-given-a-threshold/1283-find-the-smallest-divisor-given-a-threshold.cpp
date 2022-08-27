class Solution {
public:
    bool check(vector<int> &nums,int k,int mid)
    {
        int sum=0;
        for(auto z:nums)
        {
            sum+=ceil(float(z)/float(mid));
            if(sum>k)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int start=1;
        int n=nums.size();
        int end=nums[n-1];
        int ans;
        
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(check(nums,threshold,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        
        return ans;
    }
};