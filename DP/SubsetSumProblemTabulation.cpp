//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
    bool solve(vector<int>arr, int sum, int i, vector<vector<int>> &dp)
    {
        if (sum<0) return false;
        if (i==0){
            if (sum-arr[0] == 0)
                return true;
            return false;
        }
        
        if (dp[i][sum] !=-1)
            return dp[i][sum] ;
        
        bool inc= solve(arr,sum-arr[i],i-1,dp) ;
        bool exc= solve(arr,sum,i-1,dp) ;
        return dp[i][sum] = (inc || exc) ;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size() ;
        vector<vector<int>> dp(n,vector<int>(sum+1,0)) ;
        
        // step 2 : Analyse base case
        for (int s=0; s<=sum; s++)
        {
            if (s-arr[0]==0)
                dp[0][s] = true;
        }
        
        // step 3 : traverse in index and sum
        
        for (int i=1; i<n; i++){
            for (int s=0; s<=sum; s++){
                bool inc = false;
                if (s-arr[i]>=0)
                    inc = dp[i-1][s-arr[i]] ;
                    
                bool exc = dp[i-1][s] ;
                
                dp[i][s] = (inc || exc) ;
            }
        }
        return dp[n-1][sum] ;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends