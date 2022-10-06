class Solution {
public:
    void helper(int open,int close,vector<string> &ans,string temp)
    {
        if(open==0 && close==0)
        {
            ans.push_back(temp);
        }
        if(open>0)
            helper(open-1,close,ans,temp+'(');
        if(close>0 && close>open)
            helper(open,close-1,ans,temp+')');
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,n,ans,"");
        return ans;
    }
};