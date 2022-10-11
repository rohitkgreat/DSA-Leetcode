class Solution {
public:
    int dp[1001][1001];
    
    int helper(string &s,string &t,int i,int j)
    {
        if(i>=s.size() || j>=t.size())
            return 0;
      
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==t[j])
           return dp[i][j]= 1+helper(s,t,i+1,j+1);
        
        return dp[i][j]= max(helper(s,t,i+1,j),helper(s,t,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        memset(dp,-1,sizeof(dp));
        return helper(text1,text2,0,0);
    }
};