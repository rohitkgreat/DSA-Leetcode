class Solution {
public:
    
    int countHousePlacements(int n) {
        vector<int> fib(n);
        if(n==1)
            return 4;
        int mod=1000000007;
        
        fib[0]=2;
        fib[1]=3;
        for(int i=2;i<n;i++)
        {
            fib[i]=(fib[i-1]%mod+fib[i-2]%mod)%mod;
        }
        long long z=(fib[n-1])%mod;
        return (z*z)%mod;
        
    }
};