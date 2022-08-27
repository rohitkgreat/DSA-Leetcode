class Solution {
public:
    bool check(vector<int> piles,int h,int mid)
    {
        int cur=0;
        for(int i=0;i<piles.size();i++)
        {
            if(mid>=piles[i])
                cur++;
            else if(piles[i]>mid)
            {
                cur+=piles[i]/mid;
                if(piles[i]%mid!=0)
                    cur++;
            }
            if(cur>h)
                return false;
        }
        return true;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int mx=-1;
        for(auto z:piles)
            mx=max(mx,z);
        
        int end=mx;
        int ans;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(check(piles,h,mid))
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