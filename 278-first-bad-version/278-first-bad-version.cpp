// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long i=1;
        long long x=n;
        long long ans;
        while(i<=x)
        {
            long long mid=(i+x)/2;
            if(isBadVersion(mid))
            {
                ans=mid;
                x=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};