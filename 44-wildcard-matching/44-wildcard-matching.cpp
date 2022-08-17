class Solution {
public:
    bool helper(int i,int j,string &p,string &s,int **dp)
    {
        
        if(i==s.size() && j==p.size())
            return true;
        if(i==s.size() && j<p.size())
            return false;
        if(i<s.size() && j==p.size())
        {
            for(int x=i;x<s.size();x++)
                if(s[x]!='*')
                    return false;
            return true;
        }
        
        if(dp[j][i]!=-1)
            return dp[j][i];
        
        if(s[i]==p[j] || s[i]=='?')
            return dp[j][i]=helper(i+1,j+1,p,s,dp);
        
        if(s[i]=='*')
            return dp[j][i]=helper(i+1,j,p,s,dp) || helper(i,j+1,p,s,dp);
        
        return dp[j][i]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        int **dp=new int*[n+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[m+1];
            for(int j=0;j<=m;j++)
                dp[i][j]=-1;
        }
        
        
        return helper(0,0,s,p,dp);
    }
};