class Solution {
public:
    bool helper(int i,int row,int col,vector<vector<char>>& board,string word)
    {
         
        
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size())
            return false;
        
         if(board[row][col]!=word[i])
            return false;
    
        // cout<<board[row][col]<<" ";
        if(i==word.size()-1)
         {  
            cout<<"*";
            return true;
         }
       
        bool up,down,left,right;
        if(board[row][col]==word[i])
            {
                board[row][col]='.';
                up=helper(i+1,row-1,col,board,word);
                down=helper(i+1,row+1,col,board,word);
                left=helper(i+1,row,col-1,board,word);
                right=helper(i+1,row,col+1,board,word);
                board[row][col]=word[i];

            }

        return up||down||left||right;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
       
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                   
                    if(helper(0,i,j,board,word))
                        return true;
                }
            }
        return false;
    }
};