int helper(int v)
{
    int count=0;
    
    while(v)
    {
        if((1&v)>0)
            count++;
        v=v>>1;
    }
    return count;
}

// bool comp(pair<int,int> a,pair<int,int> b){
//     if(a.first<b.first)
//         return true;
//     else if(a.second<b.second)
//         return true;
    
//     return false;
// }
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            v.push_back({helper(arr[i]),arr[i]});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++)
            ans.push_back(v[i].second);
        //return v;
        return ans;
    }
};