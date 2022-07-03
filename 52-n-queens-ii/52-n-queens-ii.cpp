class Solution {
public:
    int count=0;
    bool check(int row,int col,int **dp,int n)
    {
        for(int i=0;i<=row;i++)
        {
            if(dp[i][col]==1)
                return false;
            
        if(row - i >= 0 && col - i >= 0 && dp[row-i][col-i]==1) return false;
		if(row - i >= 0 && col + i <  n && dp[row-i][col+i]==1) return false;
        }
       
        return true;
    }
    void helper(int row,int n,int **dp)
    {
       
        if(row==n)
        {     
        
            count++;
            return;
        } 
        
        for(int col=0;col<n;col++)
        {
            // cout<<row<<col<<" ";
            if(check(row,col,dp,n))
           {
             dp[row][col]=1;
             helper(row+1,n,dp);
             dp[row][col]=-1;
           }        
            
        }
    
        return;
    }
    int totalNQueens(int n) {
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }
        helper(0,n,dp);
        return count;
    }
};