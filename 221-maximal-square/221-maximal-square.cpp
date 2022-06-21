class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        if(row==1 || col==1)
        {
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                {
                    if(matrix[i][j]=='1')
                        return 1;
                }
            return 0;
        }
            
        int **dp=new int*[row];
        
        for(int i=0;i<row;i++)
        {
            dp[i]=new int[col];
                for(int j=0;j<col;j++)
                    dp[i][j]=0;
        }
        
        int mx=0;
        
            for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(matrix[0][j]=='0') 
                dp[0][j]=0;
                else if(matrix[0][j]=='1') 
                dp[0][j]=1;
                
                if(matrix[i][0]=='0') 
                dp[i][0]=0;
                else if(matrix[i][0]=='1') 
                dp[i][0]=1;
                
                mx=max(mx,max(dp[0][j],dp[i][0]));
                cout<<mx;
            }
            
    
      
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                 }
                
                mx=max(dp[i][j],mx);
            }
        return mx*mx;
    }
};