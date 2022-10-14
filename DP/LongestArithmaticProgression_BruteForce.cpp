//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
    int solve(int *arr, int n, int i, int prev_i, int diff)
    {
        if (i==n) return 0 ;
        
        
        // inc
        int inc = 0 ;
        if (diff==INT_MAX || (arr[i] - arr[prev_i] == diff) ){
            int d = (prev_i==-1)? INT_MAX:(arr[i]-arr[prev_i]) ;
            inc = 1 + solve(arr,n,i+1,i,d) ;
        }
        
        // exc
        int exc = solve(arr,n,i+1,prev_i,diff) ;
        
        
        return max(inc,exc) ;
    }
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        return solve(A,n,0,-1,INT_MAX) ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
