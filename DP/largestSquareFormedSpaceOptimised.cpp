//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0 ;
        
        vector<int> row1(m+1,0) ;
        vector<int> row2(m+1,0) ;
        
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                int r = row1[j+1] ;
                int d = row2[j] ;
                int dia = row2[j+1] ;
                
                if (mat[i][j]==1){
                    int ans = 1 + min(r,min(d,dia)) ;
                    maxi = max(maxi,ans) ;
                    row1[j] = ans;
                }
                else
                    row1[j] = 0 ;
            }
            row2=row1 ;
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
