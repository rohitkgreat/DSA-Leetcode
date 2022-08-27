class Solution {
public:
    bool check(vector<int> &position,int m,int mid)
    {
        int prev=position[0];
        m=m-1;
        int n=position.size();
        for(int i=1;i<n;i++)
        {
            if(position[i]-prev>=mid)
            {
                prev=position[i];
                m--;
                if(m==0)
                    return true;
            }
            else
                continue;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int start=0;
        int end=position[n-1];
        int ans;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(check(position,m,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};