class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> g[n+1];
        int z=times.size();
        
        for(int i=0;i<z;i++)
        {
            g[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        // for(auto m:g[2])
        //     cout<<m.first;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int dst=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            
            for(auto m:g[prev])
            {
                int nxt=m.first;
                int nxtdst=m.second;
                if(dist[nxt]>dist[prev]+nxtdst)
                {
                    dist[nxt]=dist[prev]+nxtdst;
                    pq.push({dist[nxt],nxt});
                }
            }
        }
        
       
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            else
            {
                ans=max(ans,dist[i]);
            }
        }
        return ans;
    }
};