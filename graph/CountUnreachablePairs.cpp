class UnionFind{
    public:
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n) ;
        for (int i=0; i<n; i++)
            parent[i] = i;
    }

    int Find(int x){
        if (parent[x]==x) return x;
        return parent[x] = Find(parent[x]) ;
    }
    void Union(int x, int y){
        int u = Find(x) , v = Find(y) ;
        parent[v] = u;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind* uf = new UnionFind(n) ;
        for (auto &vec : edges){
            int u = vec[0] , v = vec[1] ;
            uf->Union(u,v) ;
        }

        unordered_map<int,int> pairs;
        for (int i=0; i<n; i++)
            pairs[uf->Find(i)]++;
        
        long long sum = 0 , sumSq = 0;

        for (auto &[p,num] : pairs){
            sumSq += num*sum;
            sum+=num;
        }
        
        return sumSq;
    }
};
/*
 *	Ans for 4 , 2 , 1 group is
 *		4*2 + 4*1 + 2*1
 *	// 4(2+1) + 2*(1)
 *
 *	Always the answer is Sigma( CURRELEM * SUM_OF_ELEMENTS_ON_RIGHT  )  
 *
 *
 *
 */
