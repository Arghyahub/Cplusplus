#include<list>
#include<unordered_map>
#include<queue>
bool isCycle(unordered_map<int,list<int>> &adj,int src, unordered_map<int,bool> &visited)       //UDG
{
    unordered_map<int,int> parent ;
    // new unvisited node
    visited[src] = 1 ;
    parent[src] = -1 ;
    
    queue<int> q ;
    q.push(src) ;
    
    while(!q.empty()){
        int front = q.front() ; q.pop() ;
        
        for (auto neighbour : adj[front])
        {
            if ( visited[neighbour] && neighbour!=parent[front] )   // HOW CAN THERE BE A NODE WHICH IS VISITED BUT NOT THE PARENT 
                return true ;                                       // .:. THE GRAPH CONTAINS A CYCLE
            else if (!visited[neighbour])
            {
                q.push(neighbour) ;
                visited[neighbour] = 1 ;
                parent[neighbour] = front ;
            }
        }
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
            bool flag = isCycle(adj,val,visited) ;
            if (flag)
                return "Yes" ;
        }
    }
    return "No" ;
}