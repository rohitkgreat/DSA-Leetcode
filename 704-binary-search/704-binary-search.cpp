class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int i=0;
        
        while(i<=n)
        {
            // cout<<i<<" "<<n<<endl;
            int mid=(i+n)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                i=mid+1;
            else
                n=mid-1;
            // cout<<n;
        }
        return -1;
    }
};