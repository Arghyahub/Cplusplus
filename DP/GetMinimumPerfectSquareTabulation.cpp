//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    // int solve(int n, vector<int> &dp)
    // {
    //     if (n<0) return 1e9;
    //     if (n==0) return 0;
        
    //     if (dp[n]!=-1) return dp[n] ;
        
    //     int ans = INT_MAX;
    //     for(int i=1; i*i<=n; i++)
    //         ans = min( ans, solve(n-(i*i),dp) +1 ) ;
        
    //     return dp[n] = ans;
    // }
	public:
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,1e9) ;
	    
	    dp[0] = 0 ;
	    
	    for (int i=1; i<=n; i++){
	       // int ans = 1e9 ;
	        for (int j=1; j*j <=i ; j++){
	            int tmp = j*j ;
	            if ( i-tmp >=0)
	                dp[i]=min( dp[i], dp[i-tmp] + 1 ) ;
	        }
	    }
	    return dp[n] ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
