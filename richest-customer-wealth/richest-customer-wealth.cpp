class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int a=accounts.size();
        int sum=0,result=-1;
        for(int i=0;i<a;i++)
        {   
            sum=0;
            for(int j=0;j<accounts[i].size();j++)
                sum+=accounts[i][j];
            result=max(sum,result);
        }
        
        return result;
    }
};