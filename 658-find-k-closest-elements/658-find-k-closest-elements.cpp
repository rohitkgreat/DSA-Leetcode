class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        int n=arr.size();
        int i=0;
        for(auto z:arr)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
            i++;
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};