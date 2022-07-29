class Solution {
public:
    bool check(int mid,vector<int> &piles,int h)
    {
        if(mid==0)
            return false;
        int ans=0;
        // cout<<mid<<" ";
        for(auto x:piles)
        {
            if(mid>=x)
                ans++;
            else
            {
                if(x%mid==0)
                    ans+=x/mid;
                else
                    ans+=x/mid +1;
            }
        }
        if(ans<=h)
            return true;
        
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0;
        
        sort(piles.begin(),piles.end());
        int mx=-1;
        for(auto x:piles){
            sum+=x; 
            mx=max(mx,x);
        }
        
        int n=piles.size();
        
        int mn=sum/h;
       // cout<<"*";
        
        int start=mn,end=mx;
        int ans;
        while(start<=end)
        {
            int mid=(start+end)/2;
          
            if(check(mid,piles,h))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        
        return ans;
    }
};