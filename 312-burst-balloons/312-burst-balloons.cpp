class Solution {
public:
    
    int helper(int i,int j,vector<int> &nums,int **dp)
    {
        if(i>j)
            return 0;
        int cur=INT_MIN;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int z=i;z<=j;z++)
        {
            int ans;
            ans=nums[i-1]*nums[z]*nums[j+1]+helper(i,z-1,nums,dp)+helper(z+1,j,nums,dp);
            
            cur=max(cur,ans);
        }
        return dp[i][j]=cur;
        
    }
    int maxCoins(vector<int>& nums) {
        int z=nums.size();
        int **dp=new int*[z+1];
        for(int i=0;i<=z;i++)
        {
            dp[i]=new int[z+1];
            for(int j=0;j<=z;j++)
                dp[i][j]=-1;
        }
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        return helper(1,z,nums,dp);
    }
};