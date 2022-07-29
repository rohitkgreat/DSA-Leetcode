class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        
        int n=prices.size();
        vector<int> ans;
        int i=n-1;
        while(i>=0)
        {
            if(st.empty())
            {
                st.push(prices[i]);
                ans.push_back(prices[i]);
            }
            
            else if(prices[i]>=st.top())
            {
                ans.push_back(prices[i]-st.top());
                st.push(prices[i]);                
            }
            else
            {
                while(!st.empty() && st.top()>prices[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    st.push(prices[i]);
                    ans.push_back(prices[i]);
                }
                else
                {
                    ans.push_back(prices[i]-st.top());
                    st.push(prices[i]);
                }
            }
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};