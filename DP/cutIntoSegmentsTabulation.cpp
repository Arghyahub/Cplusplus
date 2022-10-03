#include<climits>

int cutSegments(int n, int x, int y, int z) {
    // n->length , xyz ->segments
    vector<int> dp(n+1,INT_MIN) ;
    dp[0] = 0 ;
    
    for (int i=1; i<=n; i++){
        int p = (i<x)? INT_MIN:1+dp[i-x];
        int q = (i<y)? INT_MIN:1+dp[i-y] ;
        int r = (i<z)? INT_MIN:1+dp[i-z] ;
        
        
        dp[i] = max(p,max(q,r)) ;
    }
    
    if (dp[n]<0) return 0 ;
    return dp[n] ;
}