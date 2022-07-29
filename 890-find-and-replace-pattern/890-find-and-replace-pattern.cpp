class Solution {
public:
    bool check(string s,string t)
    {
        if(s.size()!=t.size())
            return false;
        int n=s.size();
        map<char,int> mp;
        map<char,int> mp2;
        for(auto z:s)
            mp[z]++;
        for(auto x:t)
            mp2[x]++;
        
        if(mp.size()!=mp2.size())
            return false;
        else
        {
            for(int i=0;i<n;i++)
            {
                if(mp[s[i]]!=mp2[t[i]])
                    return false;
                
                if(i!=0)
                {
                    if(s[i-1]==s[i] && t[i]!=t[i-1])
                        return false;
                    else if(s[i-1]!=s[i] && t[i-1]==t[i])
                        return false;
                }
            }
        }
        
        return true;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words.size();
        vector<string> ans;        
        for(int i=0;i<n;i++)
        {
            if(check(words[i],pattern))
                ans.push_back(words[i]);
        }
        
        return ans;
        
    }
};