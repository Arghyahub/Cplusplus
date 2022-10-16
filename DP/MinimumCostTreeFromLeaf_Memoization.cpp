class Solution {
    int solve(vector<int>& arr, int start, int end, map<pair<int,int>,int> &maxi,vector<vector<int>> &dp)
    {
        if (start>=end) return 0 ;
        
        if (dp[start][end]!=-1) return dp[start][end] ;
        
        int ans = INT_MAX ;
        
        for (int k=start; k<end; k++){
            int tmp = maxi[{start,k}]*maxi[{k+1,end}] + solve(arr,start,k,maxi,dp) + solve(arr,k+1,end,maxi,dp);
            ans = min(ans,tmp) ;
        }
        return dp[start][end] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size() ;
        map<pair<int,int>,int> maxi;        // NEW CONCEPT
        
        for (int i=0; i<n; i++){
            maxi[{i,i}] = arr[i] ;
            for (int j=i+1; j<n; j++)
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]) ;
        }
        
        vector<vector<int>> dp(n,vector<int>(n,-1)) ;
        return solve(arr,0,n-1,maxi,dp) ;
    }
};
