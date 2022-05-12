#include<bits/stdc++.h>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
       stack<pair<int,int>> st;
       int n=temp.size();
        
       vector<int> ans(n,0);
        st.push({temp[n-1],n-1});
        
        for(int j=n-2;j>=0;j--)
        {
            if(st.top().first>temp[j])
            {
                ans[j]=1;
                st.push({temp[j],j});
            }
            else
            {
                while(!st.empty() && st.top().first<=temp[j])
                {
                    st.pop();
                }
                if(st.empty())
                    ans[j]=0;
                else
                    ans[j]=st.top().second-j;
                
                st.push({temp[j],j});
            }
        }
        
        return ans;
        
    }
};