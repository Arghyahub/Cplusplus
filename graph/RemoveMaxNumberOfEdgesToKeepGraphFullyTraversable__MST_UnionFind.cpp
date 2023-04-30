// Union nodes that are traversable by both
// If two nodes have the same parent allready do not join the node and make remove++
// Use the property of mst that maximum edges will be n-1
class UnionFind
{
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
        parent[pv] = pu;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind *ufAlice = new UnionFind(n+1) ;
        UnionFind *ufBob = new UnionFind(n+1) ;

        int bob = 0 , alice = 0 , remove = 0;

        for (auto &edge : edges){
            if (edge[0]!=3) continue;
            int type = edge[0] , u = edge[1] , v = edge[2] ;
            
            if (ufAlice->Find(u) != ufAlice->Find(v) ){
                ufAlice->Union(u,v) ;
                ufBob->Union(u,v) ;
                bob++;
                alice++;
            }
            else{
                remove++;
            }
        }

        for (auto &edge : edges){
            if (edge[0]==3) continue;
            int type = edge[0] , u = edge[1] , v = edge[2] ;

            if (type==1){
                if (ufAlice->Find(u) != ufAlice->Find(v)){
                    ufAlice->Union(u,v) ;
                    alice++;
                }
                else{
                    remove++;
                }
            }
            else{
                if (ufBob->Find(u) != ufBob->Find(v)){
                    ufBob->Union(u,v) ;
                    bob++;
                }
                else{
                    remove++;
                }
            }
        }


        return (alice==n-1 && bob==n-1)? remove : -1;
    }
};
