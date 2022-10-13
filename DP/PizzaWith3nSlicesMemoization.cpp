class Solution {
    int solve(vector<int>& v, int s, int e ,int k ,vector<vector<int>> &dp)
    {
        if (s>e || k==0) return 0 ;
        
        if (dp[s][k] != -1)
            return dp[s][k] ;
        
        //incl
        int inc = v[s] + solve(v,s+2,e,k-1,dp) ;
        
        //excl
        int exc = solve(v,s+1,e,k,dp) ;
        
        dp[s][k] = max(inc,exc) ;
        return dp[s][k] ;
    }
public:
    int maxSizeSlices(vector<int>& v) {
        int n = v.size() ;
        vector<vector<int>> dp(n,vector<int>(n/3+1,-1)) ;
        int op1 = solve(v,0,n-2,n/3,dp) ;
        
        fill(dp.begin(),dp.end(),vector<int>(n/3+1,-1)) ;
        int op2 = solve(v,1,n-1,n/3,dp) ;
        return max(op1,op2) ;
    }
};
