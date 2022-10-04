#include<vector>
long long int countDerangements(int n) {
    int m = 1e9+7 ;
    vector<long long int> dp(n+1,0) ;
    dp[1] = 0 ;
    dp[2] = 1 ;
    for (int i=3; i<=n; i++){
        dp[i] = ( ((i-1)%m) * ( ( (dp[i-1]%m) + (dp[i-2]%m) )%m) )%m ;
    }
    return dp[n] ;
}
