class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int n=s.length();
        
        st.push(s[0]);
        
        for(int i=1;i<n;i++)
        {
            if(!st.empty() && st.top()=='(' && s[i]==')')
                st.pop();
            else
                st.push(s[i]);
        }
        
        return st.size();
        
    }
};