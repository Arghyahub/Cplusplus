class Solution {
    int solve(vector<int>& sat, int n, int i, int time,vector<vector<int>> &dp )
    {
        if (i==n) return 0 ;
        if (dp[i][time]!=-1)
            return dp[i][time] ;
        
        int inc = sat[i]*(time+1) + solve(sat,n,i+1,time+1,dp) ;
        int exc = solve(sat,n,i+1,time,dp) ;
        return dp[i][time] = max(inc,exc) ;
    }
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end()) ;
        int n = sat.size() ;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;
        
        for (int i=n-1; i>=0; i--){
            for (int time=i; time>=0; time--){
                int inc = sat[i]*(time+1) + dp[i+1][time+1] ;
                int exc = dp[i+1][time] ;
                dp[i][time] = max(inc,exc) ;
            }
        }
        
        return dp[0][0] ;
    }
};
