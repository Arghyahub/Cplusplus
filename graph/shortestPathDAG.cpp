#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    //           SOURCE   ->  {DEST,WEIGHT}

    void addEdge(int u, int v, int weight)
    {
        pair<int,int> p = {v,weight} ;
        adj[u].push_back(p) ;
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout<<i.first<<" -> ";
            for (auto j : i.second)
                cout<<"{"<<j.first<<","<<j.second<<"} ";
            cout<<endl;
        }
    }

    void topo(stack<int> &st,unordered_map<int,bool> &visited,int src)
    {
        visited[src] = 1 ;

        for ( auto x : adj[src] )
        {
            if (!visited[x.first])
                topo(st,visited,x.first) ;
        }
        st.push(src) ;
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0 ;
        while(!st.empty())
        {
            int top = st.top() ; st.pop() ;

            if (dist[top]!=INT_MAX) // IF A NODE CAN'T BE REACHED , WHY PROCESS IT'S NEIGHBOURS? IT CAN'T BE A NODE OF THE PATH
            {
                for (auto i : adj[top])
                {
                    if (dist[top]+i.second < dist[i.first])
                        dist[i.first] = dist[top]+i.second ;
                }
            }
        }
    }


};


int main(){
    int n = 6 ;
    Graph g ;
    g.addEdge(0,1,5) ;
    g.addEdge(0,2,3) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,6) ;
    g.addEdge(2,3,7) ;
    g.addEdge(2,4,4) ;
    g.addEdge(2,5,2) ;
    g.addEdge(3,4,-1) ;
    g.addEdge(4,5,-2) ;

    g.printAdj() ;

    unordered_map<int,bool> visited ;
    stack<int> st ;
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            g.topo(st,visited,i) ;
        }
    }


    int src=1 ;
    vector<int> dist(n,INT_MAX) ;

    g.getShortestPath(src,dist,st) ;

    cout<<"\n Answer is : \n";

    for (int i=0; i<dist.size(); i++)
    {
        if (dist[i]==INT_MAX)
            cout<<"INF ";
        else
            cout<<dist[i]<<" " ;
    }

    return 0 ;
}

