class Solution {
public:
    void dfs(int row,int col,int cur,int newColor,vector<vector<int>>& image)
    {
        // cout<<row<<" "<<col<<endl;
        if(row<0 || row>=image.size() || col<0 || col>=image[0].size() || image[row][col]==newColor || image[row][col]!=cur)
        {
            return;
        }
        
        if(image[row][col]==cur)
            image[row][col]=newColor;
        
        dfs(row+1,col,cur,newColor,image);
        dfs(row-1,col,cur,newColor,image);
        dfs(row,col+1,cur,newColor,image);
        dfs(row,col-1,cur,newColor,image);
        
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(sr,sc,image[sr][sc],newColor,image);
        return image;
    }
};