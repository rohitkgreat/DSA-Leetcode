class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"0");
        
        for(int i=1;i<=n;i++)
        {
            if(15*i<=n)
                ans[15*i-1]="FizzBuzz";
            if(3*i<=n && ans[3*i-1]=="0")
                ans[3*i-1]="Fizz";
            if(5*i<=n && ans[5*i-1]=="0")
                ans[5*i-1]="Buzz";
            
            if(ans[i-1]=="0")
            {
                string x=to_string(i);
                ans[i-1]=x;
            }
        }
       
        return ans;
    }
};