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
    
    vector<int> key(n+1,INT_MAX) ; // weights
    vector<bool> visited(n+1,false) ;
    vector<int> parent(n+1,-1) ;
    
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
    key[1] = 0 ;
    pq.push({0,1}) ;
    parent[1] = -1 ;
    
    while(!pq.empty())        // RUNS N TIMES -> 1 bar mai ek nikle .:. n times chalao taki dubara na chale
    {
//         int mini = INT_MAX ;
        int u=pq.top().second ;pq.pop() ;
        if (visited[u]==true)                // THIS IS HOW TO GET RID OF THEM**
            continue ;
        
        
        // mark min node as true ;
        visited[u] = true ;
        
        for ( auto nb : adj[u] )
        {
            int v = nb.first , w =nb.second ;
            if ( w < key[v] && visited[v]==false ) // IF WE DON'T CHECK VISITED THEN IT WILL CREATE AN INFINITE LOOP IN UDG
            {
                key[v] = w ;
                parent[v] = u ;
                pq.push({w,v}) ;        //WE WILL BE UPLOADING A LOT OF DUPLICATE ENTRIES **
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans ;
    
    for (int i=2; i<=n; i++)
    {
        ans.push_back( { { parent[i] , i } , key[i] } ) ;
    }
    
    return ans ;
}
