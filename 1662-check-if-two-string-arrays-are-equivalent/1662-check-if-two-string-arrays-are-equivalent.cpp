class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1="";
        string ans2="";
        
        for(auto z:word1)
            ans1+=z;
        for(auto z:word2)
            ans2+=z;
        
        return ans1==ans2;
    }
};