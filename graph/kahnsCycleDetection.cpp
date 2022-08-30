#include<list>
#include<unordered_map>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj ;
    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first - 1 ;
        int v = edges[i].second - 1 ;
        
        adj[u].push_back(v) ;
    }
    
    vector<int> indegree(n) ;
    
    for (auto ls : adj)
    {
        for (auto element : ls.second)
            indegree[element] ++ ;
    }
    
    int count = 0 ;
    queue<int> q ;
    for (int i=0; i<n; i++)
        if (indegree[i]==0)
            q.push(i) ;
    
    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;
        
        count++ ;
        
        for (auto element : adj[front])
        {
                indegree[element]-- ;
                if (indegree[element]==0)
                    q.push(element) ;
        }
    }
    
    if (count == n)
        return false ;
    return true ;
}