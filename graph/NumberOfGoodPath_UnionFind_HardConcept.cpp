class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionDSU(int a, int b){
        int a1 = find(a), b1 = find(b);
        if(a1 == b1) return;
        parent[a1] = b1;
        cout<<"parent of "<<a1<<" is "<<b1<<endl;
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        map<int, vector<int>> valToNode;
        for(int i=0; i<n; ++i){
            valToNode[vals[i]].push_back(i);
        }
        
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        
        int cnt = n;
        for(auto &[value,vecNode] : valToNode){
            cout<<value<<"-"<<endl ;
            for(auto &node : vecNode){   //u
                cout<<node<<":";
               for(auto &nbr : adj[node]){   // v
                    if(vals[nbr]<=vals[node]){
                        unionDSU(nbr, node);
                        cout<<nbr<<",";
                    }
               }cout<<",";
            }cout<<endl;
            
            cout<<value<<"-> ";
            unordered_map<int,int> freq;
            for(auto &node : vecNode){
                int p = find(node);
                freq[p]++;
                cout<<node<<":"<<p<<",";
            }
            cout<<endl;
            
            for(auto &[key, val] : freq){
                cout<<key<<":"<<val<<endl;
                cnt += (val*(val-1))/2;
            }
        }
        
        return cnt;
    }
};
