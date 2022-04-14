#include<bits/stdc++.h>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        
        int l=s.length();
        
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(')
            {
               st.push({'(',i}); 
            }
            else if(s[i]==')')
            {
                if(st.size()>0 && st.top().first=='(')
                    st.pop();
                else
                    st.push({')',i});
            }
        }
        
        while(st.size()>0)
        {
            int z=st.top().second;
            s.erase(s.begin()+z);
            st.pop();
        }
      
        return s;
        
    }
};