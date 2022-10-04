class Solution {
    int solve(int n , int k){
        if (n==1) return 0 ;
        
        bool parent = (k&1)? solve(n-1,(k+1)/2) : solve(n-1,k/2) ;
        
        if (parent){ // 1
            if (k&1)
                return 1 ;
            else
                return 0 ;
        }
        else // 0
        {
            if (k&1)
                return 0 ;
            else
                return 1 ;
        }
    }
public:
    int kthGrammar(int n, int k) {
        return solve(n,k) ;
    }
};