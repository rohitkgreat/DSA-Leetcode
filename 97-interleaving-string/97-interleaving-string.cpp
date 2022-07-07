class Solution {
public:
    
    bool helper(int x,int y,int z,string &s1,string &s2,string &s3,int **dp)
    {
        if(z==s3.length())
            return true;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(x<s1.length() && s1[x]==s3[z] && y<s2.length() && s2[y]==s3[z])
           { dp[x][y]= helper(x+1,y,z+1,s1,s2,s3,dp)||helper(x,y+1,z+1,s1,s2,s3,dp);
                return dp[x][y];
           }
        
        bool a=false,b=false;
        if(x<s1.length() && s1[x]==s3[z])
            a=helper(x+1,y,z+1,s1,s2,s3,dp);
        if(y<s2.length() && s2[y]==s3[z])
            b=helper(x,y+1,z+1,s1,s2,s3,dp);
       dp[x][y]=a||b;
        return a||b;      
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        
        int x=s1.length();
        int y=s2.length();
        
        int **dp=new int*[x+5];
        
        for(int i=0;i<x+5;i++)            
        {
            dp[i]=new int[y+5];
            for(int j=0;j<y+5;j++)
                dp[i][j]=-1;
            
        }
        return helper(0,0,0,s1,s2,s3,dp);
    }
};