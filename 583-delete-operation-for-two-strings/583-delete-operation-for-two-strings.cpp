class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int **dp=new int *[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[m+1];
            for(int j=0;j<=m;j++)
            {
                dp[i][0]=0;
                dp[0][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        
        int cmn=dp[n][m];
      int ans=0;
        if(cmn<n)
            ans+=n-cmn;
        if(cmn<m)
            ans+=m-cmn;
        
        return ans;
    }
};