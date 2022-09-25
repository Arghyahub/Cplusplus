//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfsFindArt(int node, int parent, int &time, vector<int> *adj, int v,
    vector<int> &ans, vector<int> &disc, vector<int> &low, vector<bool> &visited)
    {
        
        visited[node] = true;
        disc[node] = low[node] = time++ ;
        int child=0 ;
        for (auto nbr : adj[node])
        {
            if (nbr==parent) continue ;
            
            if (!visited[nbr])
            {
                dfsFindArt(nbr,node,time,adj,v,ans,disc,low,visited) ;
                low[node] = min(low[node],low[nbr]) ;
                
                if (low[nbr] >= disc[node] && parent!=-1)
                {
                    // this is Art point
                    if (find(ans.begin(),ans.end(),node)==ans.end())
                        ans.push_back(node) ;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node],disc[nbr]) ;
            }
        }
        if (parent==-1 && child>1)
            if (find(ans.begin(),ans.end(),node)==ans.end())
                        ans.push_back(node) ;
    }
  
  
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int> ans ;
        vector<int> disc(v,INT_MAX) ;
        vector<int> low(v,INT_MAX) ;
        vector<bool> vis(v,0) ;
        
        int time = 0 ;
        for (int i=0; i<v; i++)
        {
            if (!vis[i])
                dfsFindArt(i,-1,time,adj,v,ans,disc,low,vis) ;
        }
        if (ans.empty())
        {
            ans.push_back(-1) ;
            return ans ;
        }
        sort(ans.begin(),ans.end()) ;
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends