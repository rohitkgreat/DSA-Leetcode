class Solution {
public:
    int vis[101][101];
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                vis[i][j]=false;
            }
        }
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                if(vis[i][j])
                    continue;
                vector<int>temp;
                int row=i,col=j;
                while(row<mat.size() && col<mat[0].size()){
                    temp.push_back(mat[row][col]);
                    vis[row][col]=true;
                    row++;
                    col++;
                }
                sort(temp.begin(),temp.end());
                row=i,col=j;
                int l=0;
                while(row<mat.size() && col<mat[0].size()){
                    mat[row][col]=temp[l++];
                    row++;
                    col++;
                }
            }
        }
        return mat;
    }
};