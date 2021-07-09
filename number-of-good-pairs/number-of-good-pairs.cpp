class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mp;
        
        for(auto x:nums)
            mp[x]++;
        
        int sum=0;
        for(auto x:mp)
        {
            int n=x.second-1;
            if(n>=1)
           sum+=n*(n+1)/2;
        }
        
        return sum;
    }
};