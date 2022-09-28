#include<vector>
int countDistinctWays(int nStairs) {    // TC O(N)  SC O(1)
    int mod = 1e9+7 ;
    
    int f = 1 , s = 1 ;
    
    for (int i=2; i<=nStairs; i++)
    {
        int trd = (f + s)%mod ;
        f = s;
        s = trd;
    }
    return s%mod ;
}