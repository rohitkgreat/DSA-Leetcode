class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n-2;i++)
        {     
           
            for(int j=i+1;j<n-1;j++)
            {
                int sum=nums[i]+nums[j];
                int st=j+1,end=n-1;
                int idx=-1;
                while(st<=end)
                {
                    int mid=(st+end)/2;
                    if(nums[mid]>=sum)
                    {
                        end=mid-1;
                    }
                    else
                    {
                        idx=mid;
                        st=mid+1;
                    }
                }
                if(idx!=-1)
                {
                    ans+=idx-j;
                }
                
            }
        }
        return ans;
    }
};