class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int n = word1.size() , m=word2.size() ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
        
        for (int j=0; j<=m; j++)
            dp[n][j] = m - j;
        for (int i=0; i<=n; i++)
            dp[i][m] = n - i ;
        
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                int ans = 0 ;
                if (word1[i]==word2[j])
                    ans = dp[i+1][j+1] ;
                else{
                    // insert
                    int insAns = 1 + dp[i][j+1] ;
                    // delete
                    int delAns = 1 + dp[i+1][j] ;
                    // replace
                    int repAns = 1 + dp[i+1][j+1] ;
                    ans=min(insAns,min(delAns,repAns) ) ;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0] ;
    }
};
