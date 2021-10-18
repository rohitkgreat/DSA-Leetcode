class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int curmin=INT_MAX;
        int best=0;
        
        int i=0,j=1;
        
        while(j<prices.size())
        {
            if(prices[i]<prices[j])
            {
                curmin=prices[i];
                best=max(best,prices[j]-prices[i]);
            }
            else{
                i=j;
            
                
            }
            j++;
        }
        return best;
    }
};