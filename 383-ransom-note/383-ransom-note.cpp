class Solution {
public:
    bool helper(int i,int j,string &s,string &t)
    {
        if(j>=t.size() && i<s.size())
            return false;
        if(i>=s.size())
            return true;
        
        if(s[i]==t[j])
            return helper(i+1,j+1,s,t);
        return helper(i,j+1,s,t);
    }
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        return helper(0,0,ransomNote,magazine);
    }
};