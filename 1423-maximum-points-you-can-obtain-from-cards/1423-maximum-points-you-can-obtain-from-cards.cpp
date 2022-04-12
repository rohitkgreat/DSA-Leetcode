class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        
        int sum=0;
        for(auto z:card)
            sum+=z;
        int n=card.size();
        int l=n-k;
        
        int i=0,j=1;
        
        int minsum=card[0];;
        while(j<n)
        {
            
            if(j-i==l)
            {
                int cursum=minsum;
                while(j<n)
                {
                    cursum+=card[j]-card[i];
                    minsum=min(minsum,cursum);
                    i++;
                    j++;
                }
                return sum-minsum;
            }
            minsum+=card[j];
            j++;
            
        }
        
        return sum;
    }
};