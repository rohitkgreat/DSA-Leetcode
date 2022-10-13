class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0)
            return 0;
        if(left==right)
            return left;
        bool flag=false;
        for(int i=0;i<31;i++)
        {
            long long x=pow(2,i)-1;
            long long y=pow(2,i+1)-1;
            
            if(left>=x && left<y)
            {
                flag=true;
                if(right>y)
                    return 0;
                // break;
            }
            if(flag)
                break;
            
        }
        long long ans=left;
        for(long long i=left+1;i<=right;i++)
            ans=ans&i;
        
        int z=ans;
        return z;
    }
};