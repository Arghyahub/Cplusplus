#include<list>
#include<unordered_map>
#include<queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int,list<int>> adj ;
    for (int i=0; i<e; i++)
    {
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        
        adj[u].push_back(v) ;
    }
    
    vector<int> indegree(v) ;
    
    for (auto ls : adj)                         // STORE THE INDEGREE OF NODES AND PUSH NODES WITH ZERO INDEGREE (MEANS START)
    {
        for (auto element : ls.second)
            indegree[element] ++ ;
    }
    
    vector<int> ans ;
    queue<int> q ;
    for (int i=0; i<v; i++)
        if (indegree[i]==0)
            q.push(i) ;
    
    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;
        
        ans.push_back(front) ;              // THE NODE THATS POPPED OUT IS THE FIRST ANSWER

        for (auto element : adj[front])     // IF YOU HAVE DELETED THE ELEMENTS THEN ITS NEIGHBOURS WOULD HAVE ONE LESS INDEGREE
        {
            indegree[element]-- ;           // --
            if (indegree[element]==0)       // IF INDEGREE == 0 PUSH IT INTO QUEUE
                q.push(element) ;
        }
    }
    return ans ;
}