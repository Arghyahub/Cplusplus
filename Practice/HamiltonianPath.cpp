//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dfs(unordered_map<int,vector<int>> &adj,vector<bool> &vis, int n)
    {
        if (vis[n]) return 0 ;
        vis[n] = true;
        int ans=0 ;
        for (auto e : adj[n])
            ans=max(ans, 1+dfs(adj,vis,e) ) ;
        vis[n] = false;
        return ans;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // If two vetex are visited more than once then false
        // if a vertex is not visited then false
        unordered_map<int,vector<int>> adj;
        for (int i=0; i<M; i++){
            int u = Edges[i][0] ;
            int v = Edges[i][1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        
        int visNode=0;
        vector<bool> vis(N+1) ;
        
        for (int i=1; i<=N; i++){
            int currvis = dfs(adj,vis,i) ;
            visNode=max(visNode,currvis) ;
        }
        
        if (visNode!=N) return false;
        return true;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends
