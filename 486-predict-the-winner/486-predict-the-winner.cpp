class Solution {
public:
    int helper(int start,int end,vector<int>nums,bool turn,int **dp)
    {
        if(start>end)
            return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int play1;
        if(turn)
       { play1=max(helper(start+1,end,nums,false,dp)+nums[start],helper(start,end-1,nums,false,dp)+nums[end]);
         return play1; 
       }
        
        int play2=min(helper(start+1,end,nums,true,dp),helper(start,end-1,nums,true,dp));
        
        dp[start][end]=play2;
        return play2;    
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size()-1;
        int sum=0;
        
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        
        
        for(auto z:nums)
            sum+=z;
        int x= helper(0,n,nums,true,dp);
        int y=sum-x;
        
        return x>=y;
    }
};