class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>mp;
        map<char,int>mp2;
        
        for(auto z:p)
            mp[z]++;
        vector<int> ans;
        int n=s.size();
        int i=0,j=0;
        int k=p.size();
        while(j<n)
        {
            if(mp.find(s[j])==mp.end())
            {
                mp2.clear();
                i=j+1;
                j++;
            }
            else
            {
                mp2[s[j]]++;
                if(j-i+1==k)
                {
                    if(mp2==mp)
                        ans.push_back(i);
                    mp2[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};