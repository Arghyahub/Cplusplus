class Solution{
    public:
    int countSetBits(int n)
    {
        if (n==0)
            return 0;
        
        int greatest2Pow = 0;
		int greatest2PowBit = 0;
        for (int i=31; i>=0; i--)
            if ((n>>i)&1){
                greatest2PowBit = i;
                break;
            }
		greatest2Pow = (1<<greatest2PowBit) ;
        
        int numBeforeGreat = greatest2Pow * (1<<(greatest2Pow-1)) ; 	// set bits before 2^k = k*( 2*(k-1) )
        int MsbGreatToN = n - (greatest2Pow) + 1;
        
        
        return numBeforeGreat + MsbGreatToN + countSetBits(n-greatest2Pow) ;
    }
};
