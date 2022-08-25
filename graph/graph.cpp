#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{
    public:

    unordered_map< int , list<int> > adj ;

    void addEdge(int node1, int node2, bool direction)
    {
        // direction 0 : Undirectional
        // direction 1 : directed graph

        adj[node1].push_back(node2) ;

        if (direction==0)                   // If its undirected
            adj[node2].push_back(node1) ;

    }


    void printAdjList()
    {
        for (auto i : adj)
        {
            cout<<i.first<<" -> " ;
            for (auto j : i.second)
                cout<<j<<", " ;
            cout<<endl;
        }
    }

};


int main(){

    int n ;
    cout<<"Enter number of nodes : ";
    cin>>n ;

    int e ;
    cout<<"Enter number of edges : ";
    cin>>e ;

    graph g ;

    cout<<"Enter nodes : \n" ;
    for (int i=0; i<e; i++)
    {
        int n1, n2 ;
        cin>>n1>>n2 ;
        // creating an undirected graph
        g.addEdge(n1,n2,0) ;
    }
    
    g.printAdjList();

    return 0 ;
}