class Solution {
public:
    int longestValidParentheses(string s) {
       
        stack<int> idx;
        idx.push(-1);
        
        stack<char> st;
        st.push(s[0]);
        idx.push(0);
        int ans=0;
        
        int n=s.size();
        
        for(int i=1;i<n;i++)
        {
            if(!st.empty() && st.top()=='(' && s[i]==')')
            {
                idx.pop();
                st.pop();
                ans=max(ans,i-idx.top());
            }
            else
            {
                st.push(s[i]);
                idx.push(i);
            }
        }
        
        return ans;
        
        
    }
};