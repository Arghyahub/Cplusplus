class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size() ;
        vector<int> indegree(N,0) ;
        unordered_map<int,vector<int>> adj;
        for (auto &vec : edges){
            adj[vec[0]].push_back(vec[1]) ;
            indegree[vec[1]]++;	// Insert all nodes indegree
        }
        
        queue<int> zeroIn;
        
        for (int i=0; i<N; i++)
            if (indegree[i]==0)		// Insert all nodes with indegree=0 because they will be the starting point
                zeroIn.push(i) ;
        
        vector<vector<int>> nodecolor(N,vector<int>(26,0)) ;

        for (int i=0; i<N; i++)
            nodecolor[i][colors[i]-'a']++;	// insert colors for all nodes

        int count = 0 , ans = 0;
        while (!zeroIn.empty()){
            int src = zeroIn.front() ;
            zeroIn.pop() ;
            count++;	// count nodes, if all nodes are not visited then there exists a loop in one of the components hence it can't be a valid ans
            for (auto nbr : adj[src]){
                for (int i=0; i<26; i++){
                    nodecolor[nbr][i] =
                      max(nodecolor[nbr][i],nodecolor[src][i]+(colors[nbr]-'a'==i? 1:0) );
					// Parent impart their color to child, store the color of that parent which is highest in value. and add 1 if color of nbr is also true for that color
                }

                indegree[nbr]--;
                if (indegree[nbr]==0)	// when parents removed, indegree decreases hence that is suitable to become the next parent
                    zeroIn.push(nbr) ;
            }
            ans = max(ans,*max_element(nodecolor[src].begin(),nodecolor[src].end())) ;
        }

        return (count==N)? ans : -1;
    }
};
