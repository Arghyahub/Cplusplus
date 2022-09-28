#include<vector>
int countDistinctWays(int nStairs) {    // SC O(N)  TC O(N)
    int mod = 1e9+7 ;
    vector<int> dp(nStairs + 1,0) ;
    dp[0]=1 ;
    dp[1]=1 ;
    
    for (int i=2; i<=nStairs; i++)
    {
       dp[i] = (dp[i-1] + dp[i-2] )%mod ;
    }
    return dp[nStairs]%mod ;
}