class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)     {
        vector<pair<int,double>> g[n];
        int z=edges.size();
        for(int i=0;i<z;i++)
        {
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,INT_MIN);
        
        dist[start]=1;
        pq.push({1,start});
        
        while(!pq.empty())
        {
            double prevdist=pq.top().first;
            int prev=pq.top().second;
            
            pq.pop();
            
            for(auto z:g[prev])
            {
                int nxt=z.first;
                double cost=z.second;
               
                if(dist[nxt]<cost*dist[prev])
                {
                    dist[nxt]=cost*dist[prev];
                    pq.push({dist[nxt],nxt});
                }
            }
        }
        
        for(auto k:dist)
            cout<<k<<" ";
        
        return dist[end]==INT_MIN?0.0000:dist[end];
        
        
    }
};