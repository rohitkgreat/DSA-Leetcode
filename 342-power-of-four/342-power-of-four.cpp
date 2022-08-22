class Solution {
public:
    bool isPowerOfFour(int n) {
        int msb=-1;
        int cnt=0;
        int i=0;
        while(n)
        {           
            if(n&1)
            {
                cnt++;
                msb=i;
            }
            if(cnt>1)
                return false;
             n=n>>1;
            i++;
        }
        if(msb%2==0)
            return true;
    return false;
    }
};