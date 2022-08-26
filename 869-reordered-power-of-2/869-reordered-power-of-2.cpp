class Solution {
public:
    bool hain(int z)
    {
        while(z)
        {
            if(z%2!=0)
                return false;
            z=z/2;
            if(z==1)
                return true;
            
        }
        return false;
    }
    bool check(string s)
    {
        int z=stoi(s);
        if(hain(z))
            return true;
        return false;
    }
    bool reorderedPowerOf2(int n) {
        if(n==1)
            return true;
        string ans=to_string(n);
        sort(ans.begin(),ans.end());
        if(check(ans))
            return true;
        while(next_permutation(ans.begin(),ans.end()))
        {
            if(check(ans))
                return true;
        }
        
        return false;       
        
    }
};