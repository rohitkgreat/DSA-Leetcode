class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int a=pow(2,n);
        int ans=0;
        for(int i=0;i<a;i++)
        {   int j=0;
            int z=i;
            int xorsum=0;
            while(z)
            {
                if(z&1)
                    xorsum=xorsum^nums[j];
                j++;
                z=z>>1;
            }
         ans+=xorsum;
        }
        
        return ans;
    }
};