class Solution {
public:
  
    int maxScoreSightseeingPair(vector<int>& values) {
      
        int mx=values[0];
        int ans=0;
        
        for(int i=1;i<values.size();i++)
        {
            int cur=mx+values[i]-i;
            ans=max(ans,cur);
            int big=values[i]+i;
            mx=max(mx,big);
        }
        
        return ans;
      
        
    }
};