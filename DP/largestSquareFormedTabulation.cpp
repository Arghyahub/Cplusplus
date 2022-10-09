//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    // int solve(int i, int j, vector<vector<int>> &mat, int &maxi,vector<vector<int>> &dp)
    // {
    //     if (i>=mat.size() || j>=mat[0].size())
    //         return 0 ;
            
    //     if (dp[i][j]!=-1) return dp[i][j] ;
        
    //     int right = solve(i,j+1,mat,maxi,dp) ;
    //     int down = solve(i+1,j,mat,maxi,dp) ;
    //     int dia = solve(i+1,j+1,mat,maxi,dp) ;
        
    //     if (mat[i][j]==1){
    //         int ans = 1 + min(right,min(down,dia)) ;
    //         maxi=max(maxi,ans) ;
    //         return dp[i][j] = ans;
    //     }
    //     else{
    //         return dp[i][j] = 0 ;
    //     }
        
    // }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0 ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
        
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                int r = dp[i][j+1] ;
                int d = dp[i+1][j] ;
                int dia = dp[i+1][j+1] ;
                
                if (mat[i][j]==1){
                    int ans = 1 + min(r,min(d,dia)) ;
                    maxi = max(maxi,ans) ;
                    dp[i][j] = ans;
                }
                else
                    dp[i][j] = 0 ;
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
