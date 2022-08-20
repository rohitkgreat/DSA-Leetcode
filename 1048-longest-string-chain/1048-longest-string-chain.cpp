class Solution {
public:
    static bool comp(string a,string b){
        return a.size()<b.size();
    }
    bool check(string &a,string &b)
    {
        if(a.size()!=b.size()+1)
            return false;
        
        int i=0,j=0;
        
        while(i<a.size())
        {
            if(a[i]==b[j])
                j++;
            i++;
        }
        
        if(j==b.size())
            return true;
        return false;
            
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
       
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]))
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};