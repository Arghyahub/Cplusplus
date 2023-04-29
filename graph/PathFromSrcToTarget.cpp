#include<list>
#include<queue>
#include<unordered_map>


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){      //UDG
	
    unordered_map<int,list<int>> adj;
    
    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first ;
        int v = edges[i].second ;
        
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    
    unordered_map<int,bool> visited ;
    unordered_map<int,int> parent ;
    
    queue<int> q ;
    q.push(s) ;
    visited[s] = 1 ;
    parent[s] = -1 ;
    
    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;
        
        for (auto x : adj[front])
        {
            if (!visited[x])
            {
                visited[x] = 1 ;
                parent[x] = front ;
                q.push(x) ;
            }
        }
    }
    
    vector<int> ans ;
    int target = t ;
    ans.push_back(t) ;
    
    while(target!=s)
    {
        target = parent[target] ;
        ans.push_back(target) ;
    }
    
    reverse(ans.begin(),ans.end()) ;
    
    return ans ;
}
