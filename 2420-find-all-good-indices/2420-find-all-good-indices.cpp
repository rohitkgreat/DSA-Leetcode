class Solution{
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n=a.size();
        vector<int> pre(n,1);
        vector<int> suf(n,1);
        vector<int> ans;
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i-1])
                pre[i]=pre[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<=a[i+1])
                suf[i]=suf[i+1]+1;
        }
        
        for(int i=k;i<n-k;i++)
        {
            if(pre[i-1]>=k && suf[i+1]>=k)
                ans.push_back(i);
        }
        return ans;
    }
};