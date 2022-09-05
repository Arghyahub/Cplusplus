#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<limits.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>> > adj ;
    for (int i=0; i<m; i++)
    {
        auto uv = g[i].first ;
        int w = g[i].second ;
        int u = uv.first ;
        int v = uv.second ;
        
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }
    
    vector<int> weight(n+1,INT_MAX) ; // weights
    vector<bool> visited(n+1,false) ;
    vector<int> parent(n+1,-1) ;
    
    
    weight[1] = 0 ;
    parent[1] = -1 ;
    
    for (int i=0; i<n; i++)        // RUNS N TIMES -> 1 bar mai ek nikle .:. n times chalao taki ek chiz 2 bar na chale
    {
        int mini = INT_MAX ;
        int u ;
        // find minimum value node
        for (int x=1; x<=n; x++){                           // EVERYTIME FETCH THE MINIMUM VALUE AND THEN PROCESS
            if ( weight[x] < mini && visited[x]==false )
            {
                u=x ;
                mini = weight[x] ;
            }
        }
        
        // mark min node as true ;
        visited[u] = true ;
        
        for ( auto nb : adj[u] )
        {
            int v = nb.first , w =nb.second ;
            if ( w < weight[v] && visited[v]==false ) // IF WE DON'T CHECK VISITED THEN IT WILL CREATE AN INFINITE LOOP IN UDG
            {
                weight[v] = w ;
                parent[v] = u ;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans ;
    
    for (int i=2; i<=n; i++)
    {
        ans.push_back( { { parent[i] , i } , weight[i] } ) ;
    }
    
    return ans ;
}