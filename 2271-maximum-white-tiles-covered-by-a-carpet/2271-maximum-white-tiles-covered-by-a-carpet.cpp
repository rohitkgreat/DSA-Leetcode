class Solution {
public:
    int helper(vector<vector<int>>& arr,int tar){
        int start=0,end=arr.size()-1;
        int ind=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid][1]>tar){
                end=mid-1;
            }else{
                ind=mid;
                start=mid+1;
            }
        }
        return ind;
    }
    int maximumWhiteTiles(vector<vector<int>>& arr, int len) {
        sort(arr.begin(),arr.end());
        int size=arr.size();
        vector<int>sum(size,0);
        sum[0]=(arr[0][1]-arr[0][0]+1);
        for(int i=1;i<size;i++){
            sum[i]=sum[i-1]+(arr[i][1]-arr[i][0]+1);
        }
        int ans=1;
        for(int i=0;i<arr.size();i++){
            int start=arr[i][0];
            int end=arr[i][1];
            int size1=end-start+1;
            int last=len-1+start;
            int temp=helper(arr,last);
            if(temp<i){
                int count=last-arr[temp+1][0]+1;
                ans=max(ans,count);
                continue;
            }else{
                int count=sum[temp];
                if(i!=0){
                    count-=sum[i-1];
                }
                int temp1=0;
                if(temp!=arr.size()-1){
                    temp1=last-arr[temp+1][0]+1;
                    if(temp1<0){
                        temp1=0;
                    }
                }
                count+=temp1;
                ans=max(ans,count);
            }
        }
        return ans;
    }
};