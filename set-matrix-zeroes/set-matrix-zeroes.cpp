class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>mp;
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    mp.push_back({i,j});
                }
            }
     
            for(auto x:mp)
            {
                int a=x.first;
                int b=x.second;
                
                for(int i=0;i<matrix[a].size();i++)
                { matrix[a][i]=0;
                  
                }
                for(int i=0;i<matrix.size();i++)
                {  
                    matrix[i][b]=0;
                    // matrix[i][a]=0;
                }
            }
       
        
    }
};