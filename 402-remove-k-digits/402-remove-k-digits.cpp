class Solution {
public:
    string removeKdigits(string num, int k) {
        int z=num.length();
        
        if(z==1 && k>0)
        {
            num.clear();
            num.push_back('0');
            return num;
        }
        z=z-1;
        int i=0;
        
        while(i<z)
        {
            int a=num[i]-'0';
            int b=num[i+1]-'0';
            
           
                if(a>b && k>0)
                {
                    num.erase(num.begin()+i);
                    if(i>0)
                    i=i-1;
                    k--;
                }
            else
            i++;
            
               if(k==0)
                break;
            
            z=num.length()-1;
        }
        
        
//             i=0;
//             while(i<z && k!=0)
//             {
//             int a=num[i]-'0';
//             int b=num[i+1]-'0';
            
           
//                 if(a>b)
//                 {
//                     num.erase(num.begin()+i);
//                     i--;
//                     k--;
//                 }
//                 else if(a==b)
//                 {
//                     if(z-i)
//                 }
           
//             if(k==0)
//                 break;
                
//                 i++;
//             }
        while(k-- && num.length()!=0)
        {
            num.pop_back();
        }
       
        
        if(num.length()==0)
        {    num.push_back('0');
             return num;
        }
        
        while(num[0]=='0' && num.length()!=1)
            num.erase(num.begin());
        
        return num;
    }
};