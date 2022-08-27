class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
      
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==0)
                    continue;
                int top=INT_MAX-10,right=INT_MAX-10;
                if(i-1>=0)
                    top=mat[i-1][j];
                if(j-1>=0)
                    right=mat[i][j-1];
                mat[i][j]=min(top,right)+1;
            }
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                    continue;
                int bottom=INT_MAX-10,left=INT_MAX-10;
                if(i+1<row)
                    bottom=mat[i+1][j];
                if(j+1<col)
                    left=mat[i][j+1];
                mat[i][j]=min(mat[i][j],min(bottom,left)+1);
            }
        }
        return mat;

    }
};