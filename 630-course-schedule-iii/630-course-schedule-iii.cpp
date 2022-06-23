class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
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
            last+=arr[i][0];
            pq.push(arr[i][0]);
            if(last>arr[i][1]){
                last-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};