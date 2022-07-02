class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle,int **dp)
    {
        if(i==triangle.size())
            return 0;
      if(dp[i][j]!=-1)
          return dp[i][j];
        
        dp[i][j]= min(helper(i+1,j,triangle,dp)+triangle[i][j],helper(i+1,j+1,triangle,dp)+triangle[i][j+1]);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       
        int n=triangle.size();
           int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }
     
        int sum=triangle[0][0];
        
        sum+= helper(1,0,triangle,dp);
        return sum;
    }
};