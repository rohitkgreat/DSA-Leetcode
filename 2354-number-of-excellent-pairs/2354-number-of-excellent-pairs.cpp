class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<long long> ans;
        
        set<long long> s;
        for(auto z:nums)
            s.insert(z);
        
        
        for(auto x:s)
        {
            int cnt=0;
            int z=x;
            
            while(z)
            {
                cnt+=z&1;
                z=z>>1;
            }
            ans.push_back(cnt);
        }
        sort(ans.begin(),ans.end());
        
        int n1=ans.size();
        
        long long anss=0;
        for(int i=0;i<n1;i++)
        {
            long long cur=ans[i];
            long long req=k-ans[i];
            if(req<=0)
                anss+=n1;
            else
            {
                int start=0,end=n1-1;
                int curans=-1;
                while(start<=end)
                {
                    int mid=(start+end)/2;
                    if(ans[mid]==req)
                    {
                        curans=mid;
                        end=mid-1;
                    }
                    else if(ans[mid]>req)
                        {end=mid-1;
                         curans=mid;
                        }
                    else
                        start=mid+1;
                }
                
                if(curans!=-1)
                anss+=n1-curans;                  
            }
                
        }
        
        return anss;
    }
};