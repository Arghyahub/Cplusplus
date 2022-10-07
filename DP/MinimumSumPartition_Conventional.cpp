//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int solveRec(int *arr, int i, int currsum, int total,vector<vector<int>> &dp)
    {
        if (currsum<0) return INT_MAX ;
        
        if (i==0){
            if (currsum-arr[i] < 0)
                return INT_MAX ;
            currsum = currsum - arr[i] ;
            int leftsum = total - currsum ;
            return abs(leftsum - currsum) ;
        }
        
        if (dp[i][currsum]!=-1)
            return dp[i][currsum] ;
        
        int inc = solveRec(arr,i-1,currsum-arr[i],total,dp) ;
        int exc = solveRec(arr,i-1,currsum,total,dp) ;
        
        return dp[i][currsum] = min(inc,exc) ;
    }

    public:
    int minDifference(int arr[], int n)  {
        int sum = 0;
        for (int i=0; i<n; i++)
            sum+=arr[i] ;
            
        vector<vector<int>> dp(n,vector<int>(sum+1,-1)) ;
        
        return solveRec(arr,n-1,sum,sum,dp) ;
       
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends