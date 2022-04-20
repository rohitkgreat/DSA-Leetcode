class Solution {
public:
    
    int helper(string s,int *dp)
    {
         if(s.size()==0)
            return 1;        
        if(s.size()==1 && s[0]!='0')
            return 1;
        if(s[0]=='0')
            return 0;
        
        int num=s[0]-'0';
        int twonum=10*num+s[1]-'0';
        
        int ans=0;
        
        if(dp[s.size()]!=-1)
            return dp[s.size()];
        else
        {
         ans+=helper(s.substr(1),dp);
         // dp[s.size()]=ans;
        }
         if(twonum<=26)
            {
             if(dp[s.size()]!=-1)
                 return dp[s.size()];
             ans+=helper(s.substr(2),dp);
        }
                     dp[s.size()]=ans;

        return ans;
    }
    
    int numDecodings(string s) {
//         int z=s.length();
//         int dp[z];
        
//         if(s[0]=='0')
//             return 0;
//         dp[0]=1;
        
//         for(int i=1;i<z;i++)
//         {
//             if(s[i-1]=='0' && s[i]=='0')
//                 dp[i]=0;
            
//             else if(s[i-1]!='0' && s[i]=='0')
//             {
//                 if(s[i-1]=='1' || s[i-1]=='2')
//                 dp[i]=(i>=2)?dp[i-2]:1;
//                 else
//                     dp[i]=0;
//             }
//             else if(s[i-1]=='0' && s[i]!='0')
//                 dp[i]=dp[i-1];
//             else
//             {
//                 if(s[i-1]<='2' && s[i]<='6')
//                 {
//                     if(i>=2)
//                         dp[i]=dp[i-1]+dp[i-2];
//                     else
//                         dp[i]=dp[i-1]+1;
//                 }
//                 else
//                     dp[i]=dp[i-1];
//             }
            
//         }
        
//         return dp[z-1];
        int x=s.size();
        int dp[x+1];
        
        memset(dp,-1,sizeof(dp));
        
        return helper(s,dp);
        
    }
};