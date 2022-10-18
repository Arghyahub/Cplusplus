class Solution {
public:
    bool isMatch(string &s, string &p) {
        int n = s.length() , m = p.length() ;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0)) ;
        // return solve(s,p,n,m,dp) ;
        
        dp[0][0] = true;
        for (int j=1; j<=m; j++){
            bool check=true;
            for (int k=1; k<=j ; k++){
                if (p[k-1]!='*'){
                    check=false;
                    break;
                }
            }
            if (check) dp[0][j] = true;
        }
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1] ;
                else if (p[j-1]=='*')
                    dp[i][j] = ( dp[i-1][j] || dp[i][j-1] ) ;
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m] ;
    }
};
