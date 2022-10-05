class Solution {
    int solve(vector<int>& v, int s, int e ,int k)
    {
        if (s>e || k==0) return 0 ;
        
        //incl
        int inc = v[s] + solve(v,s+2,e,k-1) ;
        
        //excl
        int exc = solve(v,s+1,e,k) ;
        
        return max(inc,exc) ;
    }
public:
    int maxSizeSlices(vector<int>& v) {
        int n = v.size() ;
        int op1 = solve(v,0,n-2,n/3) ;
        int op2 = solve(v,1,n-1,n/3) ;
        return max(op1,op2) ;
    }
};