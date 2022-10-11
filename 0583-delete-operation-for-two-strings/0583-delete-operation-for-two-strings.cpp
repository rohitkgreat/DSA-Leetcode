class Solution {
public:
    int helper(string s,string t,int i,int j,int **dp)
    {
        if(i>=s.length() || j>=t.length())
            return 0;
      
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==t[j])
           return dp[i][j]= 1+helper(s,t,i+1,j+1,dp);
        
        return dp[i][j]= max(helper(s,t,i+1,j,dp),helper(s,t,i,j+1,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int **dp=new int*[n+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[m+1];
            for(int j=0;j<=m;j++)
                dp[i][j]=-1;
        }
        int y=helper(word1,word2,0,0,dp);
        
        return n+m-2*y;
    }
};