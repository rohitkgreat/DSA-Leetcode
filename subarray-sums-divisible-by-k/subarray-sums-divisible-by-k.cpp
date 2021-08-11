class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pre[10001]={};
                
        int sum=0;
        pre[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sum=sum%k;
            sum=(sum+k)%k;
            pre[sum]++;
            
        }
        int ans=0;
        for(int i=0;i<k;i++)
        {
            if(pre[i]>1){
            int m=pre[i];
            ans+=m*(m-1)/2;
            }
        }
        
        return ans;
    }
};