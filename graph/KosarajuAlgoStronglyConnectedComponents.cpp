#include<unordered_map>
#include<list>
#include<stack>
void revDfs(vector<bool> &vis, int node, unordered_map<int,list<int>> &adj )
{
    vis[node] = true;
    for (auto nbr : adj[node])
        if (!vis[nbr])
            revDfs(vis,nbr,adj) ;
}
void topo(vector<bool> &vis, stack<int> &st, int node, unordered_map<int,list<int>> &adj)
{
    vis[node] = true;
    for ( auto nbr : adj[node]){
        if (!vis[nbr])
            topo(vis,st,nbr,adj) ;
    }
    st.push(node) ;
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj ;
    for (int i=0; i<edges.size(); i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        adj[u].push_back(v) ;
    }
    
    stack<int> st;
    //1. FIND TOPOLOGICAL SORT
    vector<bool> vis(v,false) ;
    for (int i=0; i<v; i++){
        if (!vis[i])
            topo(vis,st,i,adj);
    }
    
    //2. FIND TRANSPOSE OF GRAPH
    unordered_map<int,list<int>> transpose;
    for (int i=0; i<v; i++){
        vis[i] = false;
        for (int j : adj[i]){
            transpose[j].push_back(i) ;
        }
    }
    
    //3. CHECK ALL THE CONNECTIONS
    
    int count=0;
    while(!st.empty()){
        int node = st.top() ; st.pop() ;
        if (!vis[node]){
            count++ ;
            revDfs(vis,node,transpose);
        }
    }
    return count;
}