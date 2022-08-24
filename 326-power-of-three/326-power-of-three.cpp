class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        double a=(double)log10(n)/(double)log10(3);
        
        cout<<a;
        
        int b=ceil(a);
        int c=floor(a);
        
        if(b==c)
            return true;
        
        return false;
    }
};