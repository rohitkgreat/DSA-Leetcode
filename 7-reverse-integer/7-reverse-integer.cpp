class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0)
            neg=true;
        x=abs(x);
        string str=to_string(x);
        // cout<<str;
        
        
        ::reverse(str.begin(), str.end());
        
        long long y=stoll(str);
        if(y>pow(2,31))
            return 0;
        if(neg)
            y=y*-1;
        
        return y;
    }
};