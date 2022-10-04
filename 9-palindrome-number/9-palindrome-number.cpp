class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long y=0;
        int z;
        long long m=x;
        while(x)
        {
            int a=x%10;
            y=y*10+a;
            x=x/10;
        }
        return y==m;
    }
};