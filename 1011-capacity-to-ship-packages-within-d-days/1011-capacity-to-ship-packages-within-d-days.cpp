class Solution {
public:
    bool check(int cap,vector<int>& weights,int days)
    {
        int ans=1;
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+weights[i]<=cap)
                sum+=weights[i];
            else
            {
                ans++;
                sum=weights[i];
            }
        }
        return ans<=days?true:false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        int low=0;
        
        for(auto z:weights)
        {
            high+=z;
            low=max(z,low);
        }
        
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,weights,days))
            {
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};