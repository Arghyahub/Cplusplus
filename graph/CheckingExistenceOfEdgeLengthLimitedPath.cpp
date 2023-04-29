// Build the tree from smallest most weight to biggest
// and build only upto the current limit of queries,
// So queries should be sorted in terms of limit
// The key is : It says each edge should be smaller then limit

class comp {
    public:
    bool operator()(vector<int> &a, vector<int> &b){
        return a[2] < b[2] ;
    }
};

class UnionFind{
    public:
    int *parent;
    UnionFind(int n){
        parent = new int[n] ;
        for (int i=0; i<n; i++)
            parent[i] = i;
    }
    int Find(int x){
        if (parent[x]==x) return x;
        return parent[x] = Find(parent[x]) ;
    }
    void Union(int u, int v){
        int pu = Find(u) , pv = Find(v) ;
        parent[pv] = pu ;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind *uf = new UnionFind(n) ;
        int E = edgeList.size() , Q = queries.size() ;

        for (int i=0; i<Q; i++){
            queries[i].push_back(i) ;
        }

        sort(queries.begin(),queries.end(),comp()) ;
        sort(edgeList.begin(),edgeList.end(),comp()) ;

        vector<bool> ans(Q) ;
        int i = 0;

        for (auto &qvec : queries){
            int u = qvec[0] , v = qvec[1] , lim = qvec[2] , ind = qvec[3] ;
            while (i<E && edgeList[i][2] < lim ){
                uf->Union(edgeList[i][0],edgeList[i][1]) ;
                i++;
            }
            if (uf->Find(u)==uf->Find(v))   // If parents are same
                ans[ind] = true;
        }

        return ans;
    }
};


