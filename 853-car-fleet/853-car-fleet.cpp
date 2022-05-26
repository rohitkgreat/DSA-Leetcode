class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        
        if(n==1)
            return 1;
        
        vector<pair<int,int>> ans;
        
        for(int i=0;i<n;i++)
        {
            ans.push_back({position[i],speed[i]});
            
        }
        sort(ans.begin(),ans.end());
        
        vector<float> ar;
        
        for(int i=0;i<n;i++)
        {
            ar.push_back(float(float(target-ans[i].first)/float(ans[i].second)));
        }
        
        // for(auto z:ar)
        //     cout<<z<<" ";
        
        stack<float> st;
        vector<float> finl(n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
                st.push(ar[i]);
            
            else if(!st.empty() && st.top()<ar[i])
            {
                while(!st.empty() && st.top()<ar[i])
                  st.pop();
                
                if(!st.empty())
                    finl[i]=st.top();
                
                st.push(ar[i]);
                
            }
            else if(!st.empty() && st.top()>=ar[i])
            {
                finl[i]=st.top();
                st.push(ar[i]);
            }
        }
        
        // for(auto z:finl)
        //     cout<<z<<" ";
        
        int fleet=0;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(finl[i]>=0)
            continue;
            else
            fleet++;
            
        }
        return fleet;
    }
};