class Solution {
public:
    int helper(int i,int j,string &s,string &t,int **dp)
    {
        if(j==t.size())
            return 1;
        if(i>=s.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int pick=0;
        if(s[i]==t[j])
            pick=helper(i+1,j+1,s,t,dp);
        int notpick=helper(i+1,j,s,t,dp);
        
        return dp[i][j]=pick+notpick;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[m];
            for(int j=0;j<m;j++)
                dp[i][j]=-1;
        }
            return helper(0,0,s,t,dp);
    }
};