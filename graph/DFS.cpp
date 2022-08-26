void setadj(vector<vector<int>> &edges,unordered_map<int,list<int> > &adj )
{
    for(int i=0; i<edges.size(); i++)
    {
        int n1 = edges[i][0] ;
        int n2 = edges[i][1] ;
        
        adj[n1].push_back(n2) ;
        adj[n2].push_back(n1) ;
    }
}

void dfs(unordered_map<int,list<int> > &adj,unordered_map<int,bool> &visited,
        vector<int> &nodes,int val)
{
    nodes.push_back(val) ;
    visited[val]=1 ;
    
    for (auto i : adj[val])
    {
        if (!visited[i])                    // if you can insert this node go to its depth
            dfs(adj,visited,nodes,i) ;
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int> > adj ;
    unordered_map<int,bool> visited ;
    
    setadj(edges,adj);
    
    vector<vector<int>> ans ;
    for (int i=0; i<V; i++)
    {
        if (!visited[i]){
            vector<int> nodes ;
            dfs(adj,visited,nodes,i) ;
            ans.push_back(nodes) ;
        }
    }
    return ans ;
}