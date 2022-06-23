class Solution {
public:
    static bool compare(vector<int>a,vector<int>b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& arr) {
        int ans=0;
        priority_queue<int>pq;
        sort(arr.begin(),arr.end(),compare);
        int last=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int dur=arr[i][0];
            int end=arr[i][1];
            int temp=last+dur;
            if(end>=temp){
                ans++;
                last=temp;
                pq.push(dur);
            }else{
                if(pq.size()){
                    int temp1=pq.top();
                    if(dur<temp1){
                        int temp2=last-temp1+dur;
                        if(temp2<=end){
                            pq.pop();
                            last=temp2;
                            pq.push(dur);
                        }
                    }
                }
            }
        }
        return ans;
    }
};