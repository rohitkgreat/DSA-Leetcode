void helper(vector<string> &s,string z,int o,int c,int idx)
{
    if(o==0 && c==0)
    {        
        s.push_back(z);
        return;
    }
    
    if(o>0)
        helper(s,z+"(",o-1,c,idx);
    if(c>0 && c>o)
        helper(s,z+")",o,c-1,idx);
        
        return;
    
}





class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string z;
        vector<string>s;
        helper(s,z,n,n,0);
        
        return s;
        
        
    }
};