class Solution {
public:
    map<int,int>map;
    bool helper(vector<int>&nums,int k,int tar,int mask,int sum){
        if(k==0){
            return true;
        }
        if(sum==tar){
            return helper(nums,k-1,tar,mask,0);
        }
        if(sum>tar){
            return false;
        }
        if(map.count(mask)){
            return map[mask];
        }
        bool ans=false;
        for(int i=0;i<nums.size();i++){
            int p=1<<i;
            if(!(mask&p)){
                int newmask=mask | p;
                int newsum=sum+nums[i];
                ans=ans || helper(nums,k,tar,newmask,newsum);
            }
        }
        map[mask]=ans;
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
        int tar=sum/k;
        int mask=0;
        return helper(nums,k,tar,mask,0);
    }
};