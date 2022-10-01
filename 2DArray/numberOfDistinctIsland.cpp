//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
/*
1 1
1 0
will give "XRD" , FIRST RIGHT THEN BAKCTRACK THEN DOWN

1 1
0 1
will give "XRD" , THEY ARE NOT THE SAME BUT WE GET THE SAME HASH
FIRST RIGHT THEN DOWN

SO WE SOMEHOW NEED TO DIFFERENTIATE BETWEEN NORMAL MOVE AND BACKTRACKED MOVE
SO BEFORE BACKTRACKING WE ADD A SPECIAL CHARACTER

NOW 1. WILL GIVE HASH = "XR$D"
    2. WILL GIVE HASH = "XRD"
    BOTH ARE DIFFERENT :)

*/

class Solution {
    
    void dfs(string &s, int i, int j,vector<vector<int>>& grid)
    {
        // up = i<0 , down= i<grid.size() , left = j>=0 , right = j<grid[0].size()
        if ( i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 ){
            s.pop_back() ;
            return ;
        }
        
        grid[i][j]=0 ;
        //down
        s+='d' ;
        dfs(s,i+1,j,grid) ;
        
        //up
        s+='u' ;
        dfs(s,i-1,j,grid) ;
        
        //right
        s+='r' ;
        dfs(s,i,j+1,grid) ;
        
        //left
        s+='l' ;
        dfs(s,i,j-1,grid) ;
        
        s+='x' ;
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        unordered_map<string,int> ump ;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]){
                    string s = "" ;
                    dfs(s,i,j,grid) ;
                    ump[s]++;
                }
            }
        }
        
        return ump.size() ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends