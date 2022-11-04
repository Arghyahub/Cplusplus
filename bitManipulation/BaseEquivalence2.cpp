class Solution {
  public:
    string baseEquiv(int n, int m){
        for (int i=2; i<=32; i++){
            if ( pow(i,m-1) > n ) continue;	// IF THE X^M-1 IS ALREADY LARGER THAN N, THEN WE HAVE TO PUT 0 IN ITS PLACE, IF WE PUT ZERO WE WILL NO LONGER HAVE M DIGITS
            
            if (pow(i,m) > n) return "Yes" ;	// THE HIGHEST SUM OF DIGITS A BASE CAN MAKE IN RANGE 0 TO M-1 IS B^(M)-1
            
        }
        return "No" ;
    }
};
