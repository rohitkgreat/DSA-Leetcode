class Solution {
public:
    int minimumNumbers(int num, int k) {
        int ans=0;
        if(num==0)
            return 0;
        if(num%10==k)
            return 1;
        if((num-k)%10==k)
            return 2;
        if(k==0)
            return -1;
        
        int cur=k;
        int i=2;
        while(cur<num)
        {
            cur+=k;
            i++;
            if((num-cur)%10==k)
                return i;
        }
        
        return -1;
        
    }
};