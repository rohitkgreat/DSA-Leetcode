class Solution {
public:
    void helper(int pos,vector<string> &ans,string temp,unordered_map<char,string> mp,string digits)
    {
        if(pos==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        string z=mp[digits[pos]];
        
        for(int i=0;i<z.size();i++)
            helper(pos+1,ans,temp+z[i],mp,digits);
        
        return;         
            
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        string temp="";
        mp.insert({'2',"abc"});
        mp.insert({'3',"def"});
        mp.insert({'4',"ghi"});
        mp.insert({'5',"jkl"});
        mp.insert({'6',"mno"});
        mp.insert({'7',"pqrs"});
        mp.insert({'8',"tuv"});
        mp.insert({'9',"wxyz"});
              
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        helper(0,ans,temp,mp,digits);
        return ans;
    }
};