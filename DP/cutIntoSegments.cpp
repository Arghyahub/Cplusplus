#include<climits>

int maxSeg(int n, int x, int y, int z)
{
    if (n==0)
        return 0 ;
    if (n<0)
        return INT_MIN ;
    
    int l,m,o ;
    l = 1 + maxSeg(n-x,x,y,z) ;
    m = 1 + maxSeg(n-y,x,y,z) ;
    o = 1 + maxSeg(n-z,x,y,z) ;
    
    return max(l,max(m,o)) ;
}


int cutSegments(int n, int x, int y, int z) {
    // n->length , xyz ->segments
    int ans = maxSeg(n,x,y,z,dp) ;
    if (ans<0) return 0 ;
    return ans;
}