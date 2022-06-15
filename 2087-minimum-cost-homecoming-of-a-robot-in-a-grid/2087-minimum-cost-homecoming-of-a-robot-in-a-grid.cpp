class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) 
    
    {
        int i=startPos[0];
        int j=startPos[1];
        
        int endi=homePos[0];
        int endj=homePos[1];
        
        int row=abs(i-endi);
        int col=abs(j-endj);
        
        int ans=0;
        
        if(j<endj)
        {
            for(int x=j+1;x<=endj;x++)
                ans+=colCosts[x];
        }
        else if(j>endj)
        {
            for(int x=j-1;x>=endj;x--)
                ans+=colCosts[x];
        }
        if(i<endi)
        {
            for(int x=i+1;x<=endi;x++)
                ans+=rowCosts[x];
        }
        else if(i>endi)
        {
            for(int x=i-1;x>=endi;x--)
                ans+=rowCosts[x];
            
        }
        
        return ans;
        
            
    }
};