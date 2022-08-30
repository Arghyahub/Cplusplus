#include<list>
#include<unordered_map>
#include<queue>

bool isCycleDFS(unordered_map<int,list<int>> &adj,int parent ,int src ,unordered_map<int,bool> &visited)
{
    visited[src] = 1 ;
    
    for (auto neighbour : adj[src])
    {
        if (!visited[neighbour])
        {
            bool flag = isCycleDFS(adj,src,neighbour,visited) ;
            if (flag)
                return true ;
        }
        else if ( visited[neighbour] && neighbour != parent )   // HOW CAN A NODE BE ALREADY VISITED BUT NOT ITS PARENT
            return true ;
    }
    return false ;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited ;
    
    for (int i=0; i<edges.size(); i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    
    for (int val = 1; val<=n; val++){
        if (!visited[val]){
            bool flag = isCycleDFS(adj,-1,val,visited) ;
            if (flag)
                return "Yes" ;
        }
    }
    return "No" ;
}
