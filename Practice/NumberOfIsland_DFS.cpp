//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    void dfs(vector<vector<bool>> &grid, int i , int j)
    {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j]) return;
        grid[i][j]=0 ;
        dfs(grid,i-1,j) ;
        dfs(grid,i+1,j) ;
        dfs(grid,i,j+1) ;
        dfs(grid,i,j-1) ;
    }
    
    
    int solve(vector<vector<bool>> grid)
    {
        int count = 0 ;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++)
                if (grid[i][j]){
                    count++;
                    dfs(grid,i,j);
                }
        }
        return count;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> ans(operators.size());
        vector<vector<bool>> grid(n,vector<bool>(m,0)) ;
        
        for (int i=0; i<operators.size(); i++){
            int p = operators[i][0] , q = operators[i][1] ;
            grid[p][q] = 1 ;
            int num = solve(grid) ;
            ans[i] = num ;
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
