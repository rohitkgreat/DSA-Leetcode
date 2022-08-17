class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0];
        int mx=0;
        
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            int cur=prices[i]-mn;
            mx=max(mx,cur);
            mn=min(mn,prices[i]);
        }
        
        return mx;
    }
};