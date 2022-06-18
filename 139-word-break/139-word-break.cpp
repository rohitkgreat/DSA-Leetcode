class Solution {
public:
    
   bool helper(string s,unordered_map<string,int>mp,int i,int *dp)
    {
        if(i>=s.size())
            return true;
    
        string ans;
       if(dp[i]!=-1)
           return dp[i];
        for(int j=i;j<s.size();j++)
         {  
            ans.push_back(s[j]);
             if(mp.find(ans)!=mp.end())
            {
                 
               bool ans=helper(s,mp,j+1,dp);
                if(ans)
                 {
                    dp[i]=ans;
                    return ans;
                }
             }
       
        }
        dp[i]=false;           
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int>mp;
        int z=wordDict.size();
        
        int *dp=new int[s.size()];
        for(int i=0;i<s.size();i++)
            dp[i]=-1;
        
        for(int i=0;i<z;i++)
            mp[wordDict[i]]++;
        
       return helper(s,mp,0,dp);
//         if(mp.size())
//             return false;
        
//         return true;
    }
};