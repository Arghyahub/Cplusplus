#include<climits>

int maxSeg(int n, int x, int y, int z, vector<int> &dp)
{
    if (n==0)
        return 0 ;
    if (n<0)
        return INT_MIN ;
    if (dp[n]!=-1)
        return dp[n] ;
    
    int l,m,o ;
    l = 1 + maxSeg(n-x,x,y,z,dp) ;
    m = 1 + maxSeg(n-y,x,y,z,dp) ;
    o = 1 + maxSeg(n-z,x,y,z,dp) ;
    
    return dp[n] = max(l,max(m,o)) ;
}


int cutSegments(int n, int x, int y, int z) {
    // n->length , xyz ->segments
    vector<int> dp(n+1,-1) ;
    int ans = maxSeg(n,x,y,z,dp) ;
    if (ans<0) return 0 ;
    return ans;
}