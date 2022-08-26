#include<queue>
#include<unordered_map>
#include<set>

void setAdj(vector<pair<int, int>> &edges,unordered_map<int,set<int>> &adj,
           unordered_map<int,bool> &visited)
{
    for (int i=0; i<edges.size(); i++)
    {
        int n1 = edges[i].first ;
        int n2 = edges[i].second ;
        
        adj[n1].insert(n2) ;
        adj[n2].insert(n1) ;
    }
}

void getAns(vector<int> &ans,unordered_map<int,bool> &visited,
             unordered_map<int,set<int>> &adj , int val )
{
    queue<int> q ;
    q.push(val) ;
    visited[val] = 1 ;
    while(!q.empty())
    {
        int front = q.front() ; q.pop() ;
        ans.push_back(front) ;
        
        for (auto i : adj[front] )
        {
            if (!visited[i])
            {
                visited[i] = 1 ;
                q.push(i) ;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) // GIVEN THAT NODES ARE FROM 0 TO VERTEX-1
{
    unordered_map<int,set<int>> adj ;
    unordered_map<int,bool> visited ;
    
    setAdj(edges,adj,visited) ;
    vector<int> ans ;
    
    for (int i=0; i<vertex; i++)
    {
        if (!visited[i])                        // FOR DISJOINT NODES WE HAVE TO SEARCH THEM MANUALLY
        {
            getAns(ans,visited,adj,i) ;
        }
    }
    return ans ;
}