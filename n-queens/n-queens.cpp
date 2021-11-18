class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            temp[i]=s;
        
        helper(0,ans,temp,n);
        
        return ans;
    }
    
    void helper(int col,vector<vector<string>> &ans,vector<string> temp,int n)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
                if(check(i,col,temp,n))
                {
                    temp[i][col]='Q';
                    helper(col+1,ans,temp,n);
                    temp[i][col]='.';
                    
                }
        }
    }
    
    bool check(int row,int col, vector<string> temp,int n)
    {
        int x=row;
        int y=col;
        
        while(row>=0 && col>=0)
        {
            if(temp[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        int a=y;
        while(a>=0)
        {
            if(temp[x][a]=='Q')
                return false;
            a--;
        }
        while(x<n && y>=0)
        {
            if(temp[x][y]=='Q')
                return false;
            x++;
            y--;
        }
        
        return true;
    }
};