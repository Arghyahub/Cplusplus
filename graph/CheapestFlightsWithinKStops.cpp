// If you are scared of Loops and visited array problem in bfs, then use this method
// Only go to a certain node if going there requires less gas
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for (int i=0; i<flights.size(); i++){
            int u=flights[i][0] , v=flights[i][1] , w=flights[i][2] ;
            adj[u].push_back({v,w}) ;
        }

        queue<pair<int,int>> q;
        // vector<bool> vis(n,false) ;
        q.push({src,0}) ;
        int stop = 0;
        vector<int> mincost(n,INT_MAX) ;
        while (!q.empty() && stop<=k){
            int siz=q.size() ;
            for (int i=0; i<siz; i++){
                auto p = q.front() ;
                q.pop() ;
                int num = p.first , cost=p.second;
                // vis[num] = true;

                for (auto &[nbr,w] : adj[num]){
                    if (cost+w < mincost[nbr]){ // If going to a node requires less cost then only go to that node
                        q.push({nbr,w+cost}) ;
                        mincost[nbr] = w+cost ;
                    }
                }
            }
            stop++;
        }

        if (mincost[dst]==INT_MAX) return -1;
        return mincost[dst];
    }
};
