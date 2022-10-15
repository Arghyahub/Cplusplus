class Solution {
public:
    int getMoneyAmount(int n) {
        if (n<=2) return n-1 ;
        vector<vector<int>> dp(n+2,vector<int>(n+2,0)) ;
        // return solve(1,n,dp) ;
        dp[1][1] = 0;
        dp[1][2] = 1;
        
        for (int s=n; s>=1; s--){
            for (int e=s+1; e<=n; e++){
                int maxi = INT_MAX;
                for (int i=s; i<=e; i++)
                    maxi = min(maxi,i + max(dp[s][i-1],dp[i+1][e]));
                dp[s][e] = maxi ;
            }
        }
        return dp[1][n] ;
    }
};
