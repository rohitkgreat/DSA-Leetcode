class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        mp[n]++;
        
        while(n)
        {
            int sum=0;
            int temp=n;
            while(temp)
            {
                int x=temp%10;
                temp=temp/10;
                sum+=x*x;
            }
            if(sum==1)
                return true;
            if(mp.find(sum)!=mp.end())
                return false;
            mp[sum]++;
            n=sum;
            
        }
        return false;
    }
};