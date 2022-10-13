//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,0)) ;
        
        dp[0][0] = 1;
        
        for (int n=1; n<=N; n++){
            for (int x=0; x<=X; x++){
                
                long long ans = 0 ;
                for (int i=1; i<=M; i++)
                    if (x-i>=0)
                        ans += dp[n-1][x-i] ;
                
                dp[n][x] = ans ;
                
            }
        }
        return dp[N][X] ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
