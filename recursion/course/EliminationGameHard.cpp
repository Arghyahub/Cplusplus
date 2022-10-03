class Solution {
    int solve(int n){
        if (n==1)
            return n;
        return 2*(1+n/2-solve(n/2)) ;
    }
public:
    int lastRemaining(int n) {
        return solve(n) ;
    }
};