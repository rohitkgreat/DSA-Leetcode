class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n);
        v[0]=1;
        
        int a=0,b=0,c=0;
        for(int i=1;i<n;i++)
        {
            int temp1=2*v[a];
            int temp2=3*v[b];
            int temp3=5*v[c];
            
            v[i]=min(temp1,min(temp2,temp3));
            if(v[i]==temp1)
                a++;
            if(v[i]==temp2)
                b++;
            if(v[i]==temp3)
                c++;
        }
       
        return v[n-1];
    }
};