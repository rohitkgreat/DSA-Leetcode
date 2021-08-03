bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
   
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
int count(int a)
{
    int cnt=0;
    while(a)
    {
        if(a&1)
            cnt++;
        a=a>>1;
        
    }
    return cnt;
}
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int z=count(i);
            if(isPrime(z))
                ans++;
        }
        
        return ans;
    }
};