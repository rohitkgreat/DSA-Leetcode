class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        sort(nums.begin(),nums.end());
        int med=nums[n/2];
        
        long long avg=(sum/n);
        cout<<avg<<" "<<med;
        int mn=INT_MAX;
        int nb;
        for(int i=0;i<n;i++)
        {
            if(abs(avg-nums[i])<mn)
            {
                mn=abs(avg-nums[i]);
                nb=nums[i];
            }
        }
        cout<<nb<<" ";
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(nums[i]-med);
        
        return ans;
    }
};