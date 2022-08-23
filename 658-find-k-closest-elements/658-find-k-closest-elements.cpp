class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int idx=0;
        for(int i=0;i<n;i++)
            if(arr[i]<=x)
                idx=i;
        int i,j;
        vector<int> ans;
        i=idx;
        j=idx+1;
        if(arr[idx]==x)
        {
            ans.push_back(x);
            k--;
            i=idx-1;
            j=idx+1;
        }
      
        while(i>=0 && j<n && k)
        {
            if(abs(arr[i]-x)<=abs(arr[j]-x))
            {
                ans.push_back(arr[i]);
                i--;
                
            }
            
            else
            {
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        while(k>0 && i>=0)
        {
            ans.push_back(arr[i]);
            i--;
            k--;
        }
        while(k>0 && j<n)
        {
            ans.push_back(arr[j]);
            j++;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};