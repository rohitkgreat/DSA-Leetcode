class Solution {
public:
    string reverseWords(string s) {
       
        int n=s.size();
       
        while(s[0]==' ')
            s.erase(0,1);
        
        
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==' ' && s[i+1]==' ')
                while(s[i+1]==' ')
                s.erase(i+1,1);
        }
        reverse(s.begin(),s.end());
       
          while(s[0]==' ')
            s.erase(0,1);
        
        int s1=0,e;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==' ')
            {reverse(s.begin()+s1,s.begin()+i);
            s1=i+1;
            }
        }
   
        reverse(s.begin()+s1,s.end());
        return s;
        
    }
};