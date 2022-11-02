//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int solve(vector<int>& arr, int k, int i, int j, vector<vector<int>> &dp)
    {
        if (i>j)
            return arr.size() ;
        if (arr[j]-arr[i]<=k)
            return 0;
        
        if (dp[i][j]!=-1) return dp[i][j] ;
        
        int first = 1 + solve(arr,k,i+1,j,dp);
        int second = 1 + solve(arr,k,i,j-1,dp);
        
        return dp[i][j] =  min(first,second) ;
    }
    public:
    int removals(vector<int>& arr, int k){
        int n=arr.size() ;
        sort(arr.begin(),arr.end()) ;
        vector<vector<int>> dp(n,vector<int>(n,-1)) ;
        return solve(arr,k,0,arr.size()-1,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends