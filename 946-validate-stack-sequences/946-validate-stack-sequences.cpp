class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        
        int n=pushed.size();
        
        int j=0,i=0;
        while(i<n)
        {
            if(!st.empty() && popped[j]==st.top())
            {
                // cout<<st.top();
                st.pop();
                j++;
                
            }
                
            else if(pushed[i]!=popped[j])
          {   
                st.push(pushed[i]);
                i++;
          }
            
            else
               {i++;
                j++;}
            
        }
      
        while(j<n)
        {
            if(!st.empty() && st.top()==popped[j])
                st.pop();
            j++;
        }
        
        return st.empty();
    
    }
    
};