#include<list>
#include<unordered_map>
#include<stack>

void dfs(unordered_map<int,list<int>> &adj ,vector<bool> &visited ,stack<int> &st , int val)        //DAG
{
    visited[val] = 1 ;
    
    for (auto nb : adj[val])
    {
        if (!visited[nb])
            dfs(adj,visited,st,nb) ;
    }
    
    st.push(val) ;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int,list<int>> adj ;
    vector<bool> visited(v) ;
    vector<int> ans ;
    stack<int> st ;
    
    for (int i=0; i<edges.size(); i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        adj[u].push_back(v) ;
    }
    
    for (int i=0; i<v; i++)
    {
        if (!visited[i])
            dfs(adj,visited,st,i) ;
    }
    
    while(!st.empty()){
        ans.push_back(st.top()) ;
        st.pop() ;
    }
    
    return ans ;
}