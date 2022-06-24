class Solution {
public:
    int helper(int n,int i)
    {
        if(n==0)
            return i-1;
        if(n<0)
            return i-2;
       
        return helper(n-i,i+1);
    }
    int arrangeCoins(int n) {
        return helper(n-1,2);
    }
};