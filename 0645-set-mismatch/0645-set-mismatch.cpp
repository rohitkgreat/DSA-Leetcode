class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mis;
        int rep;
        map<int,int>mp;
        for(auto z:nums)
           { mp[z]++;
            if(mp[z]>1)
                rep=z;
           }
        
        for(int i=0;i<n;i++)
        {
            if(mp.count(i+1)==0)
                {mis=i+1;
                 break;
                }
        }
        return {rep,mis};
    }
};