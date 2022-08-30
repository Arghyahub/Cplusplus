#include<bits/stdc++.h>
bool isCycleDFS(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited,
               unordered_map<int,bool> DFSvisited, int val)
{
    visited[val] = 1 ;
    DFSvisited[val] = 1 ;
    
    for (auto i : adj[val])
    {
        if (!visited[i])
        {
            bool checkCycle = isCycleDFS(adj,visited,DFSvisited,i) ;
            if (checkCycle)
                return true ;
        }
        else if (visited[i] && DFSvisited[i])
            return true ;
    }
    DFSvisited[val] = 0 ;
    return false ;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj ;
    unordered_map<int,bool> visited ;
    unordered_map<int,bool> DFSvisited ;
    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first ;
        int v = edges[i].second ;
        adj[u].push_back(v) ;
    }
    
    for (int val = 1; val<=n; val++)
    {
        if (!visited[val])
        {
            bool flag = isCycleDFS(adj,visited,DFSvisited,val) ;
            if (flag)
                return true ;
        }
    }
    return false ;
}