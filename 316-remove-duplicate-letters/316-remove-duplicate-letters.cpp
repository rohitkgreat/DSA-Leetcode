class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char,int> mp;
        
        for(auto z:s)
            mp[z]++;
        
        int n=s.length();
        vector<bool> vis(26,false);
        
        for(int i=0;i<n;i++)
        {
            int x=s[i]-'a';
            if(!st.empty() && vis[x]==true )
                // && st.top()<=s[i])
            {   
                mp[s[i]]--;
                continue;
            }
            else if(!st.empty() && st.top()>s[i] && mp[st.top()]>0)
            {
                stack<char> temp;
                while(!st.empty() && st.top()>=s[i] && mp[st.top()]>0)
                {
                    int b=st.top()-'a';
                    vis[b]=0;
                    cout<<st.top()<<" ";
                    temp.push(st.top());
                    st.pop();
                
                }
                if(vis[x]==1)
                {
                    while(!temp.empty())
                    {
                        st.push(temp.top());
                       
                        int b=temp.top()-'a';
                        vis[b]=1;
                        // mp[temp.top()]--; 
                        temp.pop();
                    }
                }   
                else
                {
                st.push(s[i]);
                vis[x]=1;
                mp[s[i]]--;
                }
                
            }
            else if(vis[x]==0)
            {
                st.push(s[i]);
                mp[s[i]]--;
                vis[x]=1;
            }
            
        }
        
        string ans;
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};