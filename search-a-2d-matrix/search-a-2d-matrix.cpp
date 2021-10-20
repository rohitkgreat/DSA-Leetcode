class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0,end=matrix[0].size()-1;
        int i=0;
        
        while( start<=end && i<matrix.size())
            
        {   int mid=(start+end)/2;
            if(target==matrix[i][mid])
                return true;
         else if(target==matrix[i][start])
             return true;
         else if(target==matrix[i][end])
             return true;
            else if(target > matrix[i][mid] && target<matrix[i][end])
                start=mid+1;
            else if(target < matrix[i][mid])
                end=mid-1;
            else if(target>matrix[i][end])
                i++;
            
            
        }
        if(i<matrix.size() && matrix[i][start]==target)
            return true;
        
        return false;
    }
};