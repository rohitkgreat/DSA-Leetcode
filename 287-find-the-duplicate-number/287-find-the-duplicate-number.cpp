class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      
        int st=1;
        int end=nums.size()-1;
        int ans;
        while(st<=end)
        {
            int cnt=0;
            int mid=(st+end)/2;
            for(auto z:nums)
                if(z<=mid)
                    cnt++;
            if(cnt>mid)
                {ans=mid;
                end=mid-1;}
            else
                st=mid+1;
        }
        return ans;
    }
};