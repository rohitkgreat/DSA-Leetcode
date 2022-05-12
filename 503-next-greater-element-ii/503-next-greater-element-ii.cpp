class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       
        int n=nums.size();
        vector<int> ans(2*n,-1);
        stack<int> st;
        
        st.push(nums[n-1]);
        int cnt=0;
        
        for(int j=n-2;j>=0;j--)
        {
            if(st.top()>nums[j])
            {
                ans[2*n-cnt-2]=st.top();
                st.push(nums[j]);
            }
            else
            {
                while(!st.empty() && st.top()<=nums[j])
                    st.pop();
                
                if(!st.empty())
                    ans[2*n-cnt-2]=st.top();
                st.push(nums[j]);
            }
            
            cnt++;
        }
        
        
        for(int j=n-1;j>=0;j--)
        {
            if(st.top()>nums[j])
            {
                ans[j]=st.top();
                st.push(nums[j]);
            }
            else
            {
                while(!st.empty() && st.top()<=nums[j])
                    st.pop();
                
                if(!st.empty())
                ans[j]=st.top();
               
                st.push(nums[j]);
            }
        }
        
        vector<int> ans2(n,0);
        
        for(int i=0;i<n;i++)
            ans2[i]=ans[i];
        
        return ans2;
        
    }
};