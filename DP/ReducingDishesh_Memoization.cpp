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
        vector<vector<int>> dp(n,vector<int>(n,-1)) ;
        return solve(sat,n,0,0,dp) ;
    }
};
