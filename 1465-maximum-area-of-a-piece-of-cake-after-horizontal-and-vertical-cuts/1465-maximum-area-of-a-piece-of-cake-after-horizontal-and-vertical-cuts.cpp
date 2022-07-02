class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        int mxlength=-1;
        int mxwidth=-1;
        int cur=0;
        
        sort(hcuts.begin(),hcuts.end());
        sort(vcuts.begin(),vcuts.end());
        
        for(int i=0;i<hcuts.size();i++)
        {
            mxlength=max(mxlength,hcuts[i]-cur);
            cur=hcuts[i];
        }
        mxlength=max(mxlength,h-cur);
        cur=0;
        for(int i=0;i<vcuts.size();i++)
        {
            mxwidth=max(mxwidth,vcuts[i]-cur);
            cur=vcuts[i];
        }
        mxwidth=max(mxwidth,w-cur);
        long long x=(long long)mxwidth*(long long)mxlength;
        x=x%1000000007;
        int ans=x;
        return ans;
    }
};