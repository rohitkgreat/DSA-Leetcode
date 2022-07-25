class Solution {
public:
    bool helper(int i,int j,string &s,string &t)
    {
         if(j>=t.size())
            return true;
        
        if(i>=s.size())
            return false;
       
        if(t[j]==s[i])
            return helper(i+1,j+1,s,t);
        return helper(i+1,j,s,t);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ans=0;
        int n=s.size();
        unordered_map<string,int>mp;
        
        for(int i=0;i<words.size();i++)
        {
            if(mp.count(words[i])>0)
                {ans+=mp[words[i]];
                 continue;
                }
            int m=words[i].size();
//             int **dp=new int*[n];
//             for(int i=0;i<n;i++)
//             {
//                 dp[i]=new int[m];
//                 for(int j=0;j<m;j++)
//                     dp[i][j]=-1;
//             }
            
            if(helper(0,0,s,words[i]))
                {ans++;
                 mp[words[i]]=1;
                }
            else
                mp[words[i]]=0;
        }
        
        return ans;
    }
};