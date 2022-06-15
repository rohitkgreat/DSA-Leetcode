class Solution {
public:
    
    int helper(int row,int col,int m,int n,int **dp)
    {
        if(row==m-1 && col==n-1)
            return 1;
        if(row>=m || col>=n)
            return 0;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int right=helper(row,col+1,m,n,dp);
        int down=helper(row+1,col,m,n,dp);
        
        
        dp[row][col]= right+down;
        return dp[row][col];
        
    }
    int uniquePaths(int m, int n) {
        
        int **dp=new int*[m];
        
      
        for(int i=0;i<m;i++)
        {
            dp[i]=new int [n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }
        
        
        // int z= helper(0,0,m,n,dp);
        // for(int i=0;i<m;i++)
        // {for(int j=0;j<n;j++)
        //     cout<<dp[i][j]<<" ";
        // cout<<endl;
        // }
        // return z;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=1;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
        
        return dp[m-1][n-1];
        
        
        
//         int dp[101][101];
//         for(int i=0;i<m;i++)
//             for(int j=0;j<n;j++)
//             {
//                 dp[i][j]=1;
//             }
        
//         for(int i=1;i<m;i++)
//             for(int j=1;j<n;j++)
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
            
        
//         return dp[m-1][n-1];
    }
};