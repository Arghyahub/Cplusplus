//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class unionFind
{
    public:
    int *parent;
    int size;
    
    unionFind(int n){
        size=n;
        parent = new int[n] ;
        for (int i=0; i<n; i++)
            parent[i] = i;
    }
    
    void unionPair(int x, int nx){
        int p1 = findParent(x) ;
        int p2 = findParent(nx) ;
        parent[p1] = parent[p2] ;
    }
    
    int findParent(int x){
        if (parent[x]==x) return x;
        return parent[x] = findParent(parent[x]) ;
    }
    
    int islandCount(vector<vector<bool>> &arr){
        int row = arr.size() , col = arr[0].size() , count=0;
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (arr[i][j] && (parent[i*col+j]==i*col+j) )
                    count++;
            }
        }
        return count;
    }
    
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        vector<vector<bool>> arr(n,vector<bool>(m,false));
        vector<int> ans(op.size()) ;
        int col = m ;
        unionFind* uf = new unionFind(n*m) ;
        
        for (int p=0; p<op.size(); p++){            
            int x = op[p][0] , y = op[p][1] ;
            arr[x][y] = 1 ;
                                                    // Union either new found island with old island or vice-versa
            if (x-1>=0 && arr[x-1][y]==1) // up
                uf->unionPair(x*col+y,(x-1)*col+y) ;
            if (x+1<n && arr[x+1][y]==1) // down
                uf->unionPair(x*col+y,(x+1)*col+y) ;
            if (y-1>=0 && arr[x][y-1]==1) // left
                uf->unionPair(x*col+y,x*col+(y-1)) ;
            if (y+1<m && arr[x][y+1]==1) // right
                uf->unionPair(x*col+y,x*col+(y+1)) ;
            
            ans[p] = uf->islandCount(arr) ;         // an island is where 1 boss parent who is it's own parent exist
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends