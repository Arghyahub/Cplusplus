class Solution {rn dp[pos][currlane] = ans;
//     }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1 ;
        vector<vector<int>> dp(4,vector<int>(n+1,1e9)) ;
        
        for (int i=0; i<4; i++)
            dp[i][n] = 0 ;
        // n-1 is processed n-2 tak chalo
        // pos = n-2 to 0
        
        for (int pos=n-1; pos>=0; pos--){
            for (int currlane=1; currlane<=3; currlane++){
                
                if (obstacles[pos+1]!=currlane)
                    dp[currlane][pos] =  dp[currlane][pos+1] ;
                
                else{
                    int ans = 1e9 ;

                    for (int lane=1; lane<=3; lane++){
                        if (currlane!=lane && obstacles[pos]!=lane)
                            ans = min(ans ,1 + dp[lane][pos+1] ) ;
                    }
                    dp[currlane][pos] = ans;
                }
            }
        }
        
        return min(dp[2][0], min(dp[1][0]+1,dp[3][0]+1) ) ;
    }
};
