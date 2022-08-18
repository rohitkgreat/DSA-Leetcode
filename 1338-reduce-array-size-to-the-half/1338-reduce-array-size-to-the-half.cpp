class Solution {
public:
   static bool cmp(int a,int b)
   {
       return a>b;
   }
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        
        for(auto z:arr)
            mp[z]++;

        vector<int> ans;
        for(auto x:mp)
            ans.push_back(x.second);
        
        sort(ans.begin(),ans.end(),cmp);
        int cnt=0;
        int count=0;
        for(auto z:ans)
        {
            cnt+=z;
            count++;
            if(cnt>=n/2)
                return count;
        }
            
        return 0;
    }
};