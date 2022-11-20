class Solution {

public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size() ;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0)) ;

        dp[0][0] = true; // base case 1

        for (int i=0; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (i==0){
                    bool flag = true;
                    for (int k=j-1; k>=0; k--){
                        if (p[k]=='*')
                            k--;
                        else{
                            dp[i][j] = false;
                            flag=false;
                        }
                    }
                    if (flag)
                        dp[i][j] = true;
                }
                else 
                {    if (s[i-1]==p[j-1] || p[j-1]=='.')
                        dp[i][j] = dp[i-1][j-1] ;
                    // pres empty || pres multiple
                    else if (p[j-1]=='*'){
                        bool check=false;
                        if (s[i-1]==p[j-1-1] || p[j-1-1]=='.')
                            check = dp[i-1][j] ; 
                        dp[i][j] = ( dp[i][j-2] || check ) ;
                    }
                    else
                        dp[i][j] = false;
                }
            }
        }

        return dp[n][m] ;

    }
};
