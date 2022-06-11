// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void helper(vector<int> adj[], vector<int> &vis,vector<int> &ans,int node)
	{
	    vis[node]=1;
	    
	    for(auto x:adj[node])
	    {
	        if(vis[x]==0)
	        {
	            helper(adj,vis,ans,x);
	        }
	    }
	    ans.push_back(node);
	    
	    return;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // vector<int> deg(V,0);
	    vector<int> vis(V,0);
	    vector<int> ans;
	   // for(int i=0;i<V;i++)
	   // {
	   //     for(auto x:adj[i])
	   //     deg[x]++;
	   // }
	    
	   // for(auto z:deg)
	   // cout<<z<<" ";
	    
	   // for(int i=0;i<deg.size();i++)
	   // {
	   //     if(deg[i]==0)
	   //     {
	   //         vis[i]=1;
	   //         ans.push_back(i);
	   //     }
	   // }
	   
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        helper(adj,vis,ans,i);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	    
	   // queue<int> q;
	   // for(auto x:ans)
	   // q.push(x);
	    
	   // vector<int> fin;
	   // while(!q.empty())
	   // {
	   //     int x=q.front();
	   //     q.pop();
	   //     fin.push_back(x);
	        
	   //     for(auto z:adj[x])
	   //     {
	   //         deg[z]--;
	   //         if(deg[z]==0)
	   //         {
	                
	   //             q.push(z);
	   //         }
	   //     }
	        
	   // }
	    
	   // for(auto x:fin)
	   // cout<<x<<" ";
	   // return fin;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends