class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st;
        stack<char> st2;
        
        if(s[0]!='#')
        st.push(s[0]);
        
        if(t[0]!='#')
        st2.push(t[0]);
        
        int n=s.length();
        int n2=t.length();
        
        for(int i=1;i<n;i++)
        {
            if(!st.empty() && s[i]=='#')
                st.pop();
            else if(st.empty() && s[i]=='#')
                continue;
            else 
                st.push(s[i]);
        }
        
        for(int i=1;i<n2;i++)
        {
            if(!st2.empty() && t[i]=='#')
                st2.pop();

            else if(st2.empty() && t[i]=='#')
                continue;
            else
                st2.push(t[i]);
        }
        
        return st==st2;
    }
};