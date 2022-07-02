class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& matrix,int **dp)
    {
        if(row==matrix.size())
            return 0;
        if(col>=matrix[0].size())
            return 100000;
        
        if(dp[row][col]!=100000)
            return dp[row][col];
        
        dp[row][col]= matrix[row][col]+min(helper(row+1,col,matrix,dp),min(helper(row+1,col-1,matrix,dp),helper(row+1,col+1,matrix,dp)));
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int **dp=new int*[row];
        for(int i=0;i<row;i++)
        {
            dp[i]=new int[col];
            for(int j=0;j<col;j++)
                dp[i][j]=100000;
            
        }
        int ans=INT_MAX;
        for(int i=0;i<col;i++)
            ans=min(ans,helper(0,i,matrix,dp));
        
        return ans;
    }
};