class Solution {
public:
    int helper(int i,vector<int> &days,vector<int> &costs,map<int,int> &mp,int *dp)
    {
        if(i>=days.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        int cur=days[i];
        
        ans=min(ans,helper(i+1,days,costs,mp,dp)+costs[0]);
        int nxt=cur+7;
        int ind=days.size();
        for(auto z:mp)
        {
            if(z.first>=nxt)
            {
                ind=z.second;
                break;
            }
        }
       
        ans=min(ans,helper(ind,days,costs,mp,dp)+costs[1]);
        
        nxt=cur+30;
        ind=days.size();
        for(auto z:mp)
        {
         if(z.first>=nxt)
         {
             ind=z.second;
             break;
         }
        }
        
        ans=min(ans,helper(ind,days,costs,mp,dp)+costs[2]);
        dp[i]=ans;
        return ans;
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int,int> mp;
        for(int i=0;i<days.size();i++)
            mp.insert({days[i],i});
        int n=days.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        return helper(0,days,costs,mp,dp);
        
    }
};