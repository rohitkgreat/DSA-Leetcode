double helper(double x, int n)
{
    if(n==0)
        return 1;
    double z=helper(x,n/2);
    z*=z;
    
    if(n&1)
        return x*z;
    
    return z;
}

double help(double x,int n)
{
    if(n==0)
        return 1;
    double z=helper(x,n/2);
    z*=z;
    double ans=1/z;
    if(n&1)
        return (1/x)*ans;
    
    return ans;

    
}


class Solution {
public:
    double myPow(double x, int n) {
        if(n>=0)
        return helper(x,n);
        else
            return help(x,n);
        
    }
};