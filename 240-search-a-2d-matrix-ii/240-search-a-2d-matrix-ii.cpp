class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        for(int i=0;i<row;i++)
        {
            if(target==matrix[i][col-1] || target==matrix[i][0])
                return true;
            if(target<matrix[i][col-1] && target>matrix[i][0])
            {
                int start=0,end=col-1;
               
                while(start<=end)
                {
                    int mid=(start+end)/2;
                    // cout<<mid<<"\n";
                    if(target==matrix[i][mid])
                        return true;
                    else if(target>matrix[i][mid])
                        start=mid+1;
                    else
                        end=mid-1;
                }
                
                       
            }
        }
        // cout<<"out";
        for(int i=0;i<col;i++)
        {
            if(target==matrix[0][i] || target==matrix[row-1][i] )
                return true;
            if(target<matrix[0][i] && target>matrix[row-1][i])
            {
                int start=0,end=row-1;
                
                while(start<=end)
                {
                    int mid=(start+end)/2;
                    if(target==matrix[mid][i])
                        return true;
                    else if(target>matrix[mid][i])
                        start=mid+1;
                    else
                        end=mid-1;
                }
              
            }
        }
        
        return false;
        
    }
};