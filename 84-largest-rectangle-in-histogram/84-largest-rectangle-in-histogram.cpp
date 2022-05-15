class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    
        stack<pair<int,int>> left;
        stack<pair<int,int>> right;
        
        int n=heights.size();
        
        vector<int> lt(n,-1);
        vector<int> rt(n,-1);
        
        left.push({heights[0],0});
        
        for(int i=1;i<n;i++)
        {
            if(left.top().first<heights[i])
            {
                lt[i]=left.top().second;
                left.push({heights[i],i});
            }
            else
            {
                while(!left.empty() && left.top().first>=heights[i])
                {
                    left.pop();
                }
                
                if(!left.empty())
                    lt[i]=left.top().second;
                
                left.push({heights[i],i});
            }
        }
        
        right.push({heights[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            if(right.top().first<heights[i])
            {
                rt[i]=right.top().second;
                right.push({heights[i],i});
            }
            else
            {
                while(!right.empty() && right.top().first>=heights[i])
                {
                    right.pop();
                }
                
                if(!right.empty())
                    rt[i]=right.top().second;
                
                right.push({heights[i],i});
            }
        }
        
      
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            if(rt[i]==-1)
            {
                rt[i]=n;     
            }
        
            mx=max(mx,heights[i]*(rt[i]-lt[i]-1));
        }
        
        return mx;
        
    }
};
