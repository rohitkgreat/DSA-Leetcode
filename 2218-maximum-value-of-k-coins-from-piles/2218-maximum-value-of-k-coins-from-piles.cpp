// class Solution {
// public:
//     int helper(int i,vector<vector<int>>& piles, int k)
//     {
//         if(i>=piles.size())
//             return -100000;
//         if(k<0)
//             return -100000;
//         if(k==0)
//             return 0;
        
//         int ans=INT_MIN;
//         int x=piles[i].size();
//         int siz=min(k,x);
//         for(int j=0;j<siz;j++)
//         {
//             int y=helper(i+1,piles,k-j-1);           
//             int x=piles[i][j]+helper(i+1,piles,k-j-1);
//             x=max(x,y);
//             ans=max(ans,x);
//         }
        
//         return ans;
//     }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
//         int row=piles[0].size();
//         int col=piles.size();
        
//         for(int i=0;i<col;i++)
//         {
//             int sum=0;
//             for(int j=0;j<row;j++)
//             {
//                 sum+=piles[i][j];
//                 piles[i][j]=sum;
//             }
//         }
        
//         return helper(0,piles,k);
//     }
// };

class Solution {
public:
    int helper(vector<vector<int>>& piles,int i, int k,int**dp){
        if(k==0){
            return 0;
        }
        if(i>=piles.size()){
            return INT_MIN;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int ans=INT_MIN;
        int size1=piles[i].size();
        int size=min(k,size1);
        for(int j=0;j<=size;j++){
            int temp=helper(piles,i+1,k-j,dp);
            if(j!=0 && temp!=INT_MIN){
                temp+=piles[i][j-1];
            }
            ans=max(ans,temp);
        }
        dp[i][k]=ans;
        return ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int ans=0;
        int size=piles.size();
        int**dp=new int*[size+1];
        for(int i=0;i<=size;i++){
            dp[i]=new int[k+1];
            for(int j=0;j<=k;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<size;i++){
            int m=piles[i].size();
            for(int j=1;j<m;j++){
                piles[i][j]=piles[i][j]+piles[i][j-1];
            }
        }
        ans=helper(piles,0,k,dp);
        return ans;
    }
};