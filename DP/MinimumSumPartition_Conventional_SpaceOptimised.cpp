//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // int solveRec(int *arr, int i, int currsum, int total,vector<vector<int>> &dp)
    // {
    //     if (currsum<0) return INT_MAX ;
        
    //     if (i==0){
    //         if (currsum-arr[0] < 0)
    //             return INT_MAX ;
    //         currsum = currsum - arr[i] ;
    //         int leftsum = total - currsum ;
    //         return abs(leftsum - currsum) ;
    //     }
        
    //     if (dp[i][currsum]!=-1)
    //         return dp[i][currsum] ;
        
    //     int inc = solveRec(arr,i-1,currsum-arr[i],total,dp) ;
    //     int exc = solveRec(arr,i-1,currsum,total,dp) ;
        
    //     return dp[i][currsum] = min(inc,exc) ;
    // }

    public:
    int minDifference(int arr[], int n)  {
        int sum = 0;
        for (int i=0; i<n; i++)
            sum+=arr[i] ;
            
        vector<int> dp(sum+1,INT_MAX) ;
        
        for (int s=0; s<=sum ; s++){
            if ( s-arr[0] < 0)
                dp[s] = INT_MAX ;
            else{
                int cs = s - arr[0] ;
                int leftsum = sum - cs;
                dp[s] = abs(leftsum - cs) ;
            }
        }
        
        for (int i=1; i<n; i++){
            for (int s=sum; s>=0; s--){
                int inc = INT_MAX;
                if (s-arr[i]>=0)
                    inc = dp[s-arr[i]] ;
                
                int exc = dp[s] ;
                
                dp[s] = min(inc,exc) ;
            }
        }
        
        return dp[sum] ;
       
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