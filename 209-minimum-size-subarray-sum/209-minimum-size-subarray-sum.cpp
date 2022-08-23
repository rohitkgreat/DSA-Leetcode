class Solution {
public:
    bool helper(int mid,vector<int> &nums,int target)
    {
        
        int sum=0,j=0,i=0;
        // cout<<mid<<endl;
        while(j<nums.size())
        {            
            sum+=nums[j];
            if(j-i+1==mid)
            {
                if(sum>=target)
                    return true;
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int start=0,end=n;
        int ans=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(helper(mid,nums,target))
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