class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& nums, int tar) {
        int m=nums.size();
        int n=nums[0].size();
        int ans=0;
        int**arr=new int*[m+1];
        for(int i=0;i<=m;i++){
            arr[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                arr[i][j]=0;
            }
        }
        arr[m-1][n-1]=nums[m-1][n-1];
        for(int j=n-2;j>=0;j--){
            arr[m-1][j]=arr[m-1][j+1]+nums[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            arr[i][n-1]=arr[i+1][n-1]+nums[i][n-1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int sum=nums[i][j];
                sum+=arr[i][j+1];
                int temp=arr[i+1][j]-arr[i+1][j+1];
                sum+=temp;
                arr[i][j]=sum;
            }
        }
        for(int k=0;k<m;k++){
            for(int i=k+1;i<=m;i++){
                for(int j=0;j<=n;j++){
                    int sum=arr[k][j]-arr[i][j];
                    for(int l=j+1;l<=n;l++){
                        int temp=sum-arr[k][l]+arr[i][l];
                        if(temp==tar){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};