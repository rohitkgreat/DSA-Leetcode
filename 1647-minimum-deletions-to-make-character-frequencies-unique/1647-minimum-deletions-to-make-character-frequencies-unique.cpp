class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        
        for(auto x:s)
            v[x-'a']++;
        
        sort(v.begin(),v.end());
        
        int ans=0;
        for(int i=24;i>=0;i--)
        {
            if(v[i]==0)
                break;
            if(v[i]>=v[i+1])
               {int cur=v[i]; 
                v[i]=max(0,v[i+1]-1);
                ans+=cur-v[i];
               }
        }
        return ans;
    }
};