class Solution {
    int solve(int n)
    {
        if (n<=0) return 0;
        if (n<10) return 1;

        int len = log10(n) + 1;
        int base = pow(10,len-1) ;
        int firstDigit = n/base;
        int rem = n%base ;
        int oneInBase = 0;
        if (firstDigit==1)
            oneInBase = n - base +1;
        else
            oneInBase = base ;

        return firstDigit*(solve(base-1)) + oneInBase + solve(rem) ; 
    }
public:
    int countDigitOne(int n) {
        return solve(n) ;
    }
};