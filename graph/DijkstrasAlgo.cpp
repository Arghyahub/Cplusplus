#include<list>
#include<set>
#include<unordered_map>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {       // SHORTEST DISTANCE
    
    unordered_map<int, list< pair<int,int> > > adj;
    for (int i=0; i<edges; i++)
    {
        int u = vec[i][0] ;
        int v = vec[i][1] ;
        int w = vec[i][2] ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }
    
    set<pair<int,int>> s; // first = dist, second = node
    
    vector<int> dist(vertices,INT_MAX) ;
    dist[source] = 0 ;
    
    s.insert({0,source}) ;
    
    while(!s.empty())
    {
        auto top = *(s.begin()) ;
        s.erase(s.begin()) ;
        
        for (auto x : adj[top.second])
        {
            int distUptoP = top.first ;
            int distPtoT = x.second ;
            if (distUptoP + distPtoT < dist[x.first] /*curr dist*/ )    // REMOVE THE PREVIOUSLY ENTERED DATA, NOW THAT IT IS PROVEN IT HAS MORE WEIGHT
            {
                auto record = s.find({dist[x.first],x.first}) ;    // find curr dist , current node 
                if ( record != s.end() )                            // IF DATA EXISITS THEN DELETE IT
                {
                    s.erase(record) ;
                }
                dist[x.first] = distUptoP + distPtoT ;              // UPDATE curr DISTANCE
                s.insert({dist[x.first] , x.first }) ;  // new dist , node
            }
        }

        /**
         * @brief FOR EXAMPLE
         * 0 -> (N2,D5) , (N3,D8)
         * 2-> (n3,D2) -> NOW THAT 2-3 DIST IS SHORTER THAN 0-3 DIST
         * REMOVE THE 0-3 RECORD (IF EXISTS) FROM SET AND THEN UPDATE THE VALUE AND ENTER IT INTO THE SET 
         */
    }
    return dist ;
}