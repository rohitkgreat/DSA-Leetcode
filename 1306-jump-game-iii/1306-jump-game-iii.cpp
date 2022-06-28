class Solution {
public:
    bool helper(vector<int>& arr, int start,vector<bool> &vis)
    {
        if(start<0 || start>=arr.size() || vis[start]==true)
            return false;
      
        if(arr[start]==0)
            return true;
        vis[start]=true;        
        return helper(arr,start-arr[start],vis)||helper(arr,start+arr[start],vis);
        
    }
    bool canReach(vector<int>& arr, int start) {
       
        int n=arr.size();
        vector<bool> vis(n,false);
        return helper(arr,start,vis);
    }
};