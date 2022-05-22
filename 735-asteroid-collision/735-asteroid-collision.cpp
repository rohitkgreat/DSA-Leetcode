class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
       stack<int> st;
        int n=asteroids.size();
        bool used=false;
        for(int i=0;i<n;i++)
        {
           if(asteroids[i]>0 || st.empty())
               st.push(asteroids[i]);
            else
            {
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top())
                    st.pop();
                if(!st.empty() && st.top()==abs(asteroids[i]))
                    st.pop();
                
                else
                {
                    if(st.empty() || st.top()<0)
                        st.push(asteroids[i]);
                }
            }
        }
        
        vector<int> ans;
        
        while(!st.empty())
        {
            int z=st.top();
            ans.push_back(z);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};