class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> mp;
        
        int x=s.length();
        int y=t.length();
        
        for(int i=0;i<x;i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0;i<y;i++)
        {
            mp[t[i]]--;
            if(mp[t[i]]==0)
                mp.erase(t[i]);
        }
        
        if(mp.size()==0)
            return true;
        return false;
        
    }
};