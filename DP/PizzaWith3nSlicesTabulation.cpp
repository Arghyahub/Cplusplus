class Solution {
    int solveTab(vector<int>& v, int s, int e)
    {
        int n = v.size() ;
        vector<vector<int>> dp(n+2,vector<int>(n/3+1,0)) ;
        
        for (int i=e; i>=s; i--){
            for (int k=1; k<=n/3; k++){
                int inc = v[i] + dp[i+2][k-1] ;
        
                //excl
                int exc = dp[i+1][k] ;

                dp[i][k] = max(inc,exc) ;
            }
        }
        
        return dp[s][n/3] ;
    }
public:
    int maxSizeSlices(vector<int>& v) {
        int n = v.size() ;
        int op1 = solveTab(v,0,n-2) ;
        
        int op2 = solveTab(v,1,n-1) ;
        return max(op1,op2) ;
    }
};
