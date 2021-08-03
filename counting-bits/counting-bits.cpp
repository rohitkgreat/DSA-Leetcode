void help(vector<int> &v,int i)
{
    int count=0;
    while(i)
    {
        if(i&1>0)
            count++;
        i=i>>1;
    }
    v.push_back(count);
}


class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> v;
        
        for(int i=0;i<=n;i++)
        {
            help(v,i);
        }
        
        return v;
        
    }
};