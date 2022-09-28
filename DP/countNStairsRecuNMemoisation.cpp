#include<vector>
int mod = 1e9+7 ;
int count(int n, vector<int> &dp)
{
    if (n==0)
        return 1 ;
    if (n<0)
        return 0 ;
    if (dp[n]!=-1)
        return dp[n] ;
    
    dp[n] = ( count(n-1,dp) + count(n-2,dp) )%mod ;
    return dp[n] ;
}
int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs + 1,-1) ;
    dp[0]=1 ;
    dp[1]=1 ;
    
    return (count(nStairs,dp))%mod ;
}