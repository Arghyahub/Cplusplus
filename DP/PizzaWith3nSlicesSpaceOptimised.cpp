class Solution {
    int solveTab(vector<int>& v, int s, int e)
    {
        int n = v.size() ;
        vector<int> row2(n/3+1,0) ;
        vector<int> row1(n/3+1,0) ;
        vector<int> row0(n/3+1,0) ;
        
        for (int i=e; i>=s; i--){
            for (int k=1; k<=n/3; k++){
                int inc = v[i] + row2[k-1] ;
        
                //excl
                int exc = row1[k] ;

                row0[k] = max(inc,exc) ;
            }
            row2=row1;
            row1=row0;
        }
        
        return row0[n/3] ;
    }
public:
    int maxSizeSlices(vector<int>& v) {
        int n = v.size() ;
        int op1 = solveTab(v,0,n-2) ;
        
        int op2 = solveTab(v,1,n-1) ;
        return max(op1,op2) ;
    }
};
