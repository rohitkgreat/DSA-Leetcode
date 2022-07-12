class Solution {
public:
    bool helper(vector<int>& arr,int left,int tar,int mask,int sum,int**dp){
        if(left==0){
            return true;
        }
        if(sum==tar){
            return helper(arr,left-1,tar,mask,0,dp);
        }
        if(dp[mask][left]!=-1){
            return dp[mask][left];
        }
        bool ans=false;
        for(int i=0;i<arr.size();i++){
            int p=1<<i;
            if(!(mask&p)){
                if((arr[i]+sum)>tar){
                    return false;
                }
                int newmask=mask|p;
                ans=helper(arr,left,tar,newmask,sum+arr[i],dp);
                if(ans){
                    dp[mask][left]=ans;
                    return ans;
                }
                dp[newmask][left]=false;
            }
        }
        dp[mask][left]=false;
        return ans;
    }
    bool makesquare(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%4!=0){
            return false;
        }
        sum=sum/4;
        sort(arr.begin(),arr.end());
        int mask=0;
        int p=1<<16;
        int**dp=new int*[p];
        for(int i=0;i<p;i++){
            dp[i]=new int[5];
            for(int j=0;j<5;j++){
                dp[i][j]=-1;
            }
        }
        return helper(arr,4,sum,mask,0,dp);
    }
};