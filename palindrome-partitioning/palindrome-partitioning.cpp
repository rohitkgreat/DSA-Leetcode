class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> finall;
        vector<string> ans;
        helper(s,0,ans,n,finall);
        
        return finall;
        
    }
    void helper(string s,int idx,vector<string> ans,int n,vector<vector<string>> &finall)
    {
        if(idx==n)
        {
        finall.push_back(ans);
         return;
            
        }
        
       for(int i=idx;i<n;i++)
       {
           if(check(s,idx,i)){
           ans.push_back(s.substr(idx,i-idx+1));
           helper(s,i+1,ans,n,finall);
           ans.pop_back();
           }
       }
        
    }
    
    bool check(string s,int x,int y)
    {
        if(x==y || x>y)
            return true;
        
        if(s[x]!=s[y])
            return false;
       
        return check(s,x+1,y-1);
        
    }
};