class Solution {
public:
    int fact(int n)
    {
        long long ans=1;
        for(int i=1;i<=n;i++)
           {
            ans=ans%1000000007;
            ans*=i;
           }
        
        int z=ans%1000000007;
        return z;
    }
    vector<int> getRow(int row) {
        vector<int> tmp;
        tmp.push_back(1);
        
        if(row==0)
            return tmp;
        
        int z=row-1;
        long long int ans=1;
        for(int i=1,up=row,down=1;i<row;i++,up--,down++)
        {
            ans=ans*up/down;
            tmp.push_back(ans);
        }
        tmp.push_back(1);
        
        return tmp;
    }
};