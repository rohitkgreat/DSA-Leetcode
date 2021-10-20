class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cnt1=0;
        int cnt2=0;
        int ele1=-1;
        int ele2=-1,n=nums.size();
        
        for(auto x:nums)
        {
            if(ele1==x)
              cnt1++;
            else if(ele2==x)
                cnt2++;
            else if(cnt1==0)
            {
                ele1=x;
                cnt1=1;
            }
            else if(cnt2==0)
            {
                ele2=x;
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        int z=n/3;
        
        for(auto x:nums)
        {
            if(x==ele1)
            {
                cnt1++;
            } 
            else if(x==ele2)
                cnt2++;
        }
        vector<int>ans;
        if(cnt1>z)
            ans.push_back(ele1);
        if(cnt2>z)
            ans.push_back(ele2);
        
        return ans;
    }
};