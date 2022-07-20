class Solution {
public:
    bool issubsequence(string& s1, string& s2){
        int n = s1.length(), m = s2.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        return i == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        map<string,int>map;
        for(int i=0;i<words.size();i++){
            if(map.count(words[i])>0){
                ans+=map[words[i]];
                continue;
            }
            if(issubsequence(words[i],s)){
                map[words[i]]=1;
                ans++;
            }else{
                map[words[i]]=0;
            }
        }
        return ans;
    }
};