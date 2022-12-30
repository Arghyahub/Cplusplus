class Solution {
public:
    int numSquares(int n) {
        static vector<int> numOfElemFor = {0} ;
        while (numOfElemFor.size()<=n){
            int currElem = numOfElemFor.size() ;
            int minim = INT_MAX;
            for (int i=1; i*i<=currElem; i++)   // All sq elem upto curr elem
            {   // Any currnum can be represented as sum of
                // A(1) perfSq + NumofElemItTookToMake(n-thatPerfSq)
                // 12 => 4(1) + 8(we will get that)
                // 12 => 9(1) + 3(we will get that)
                minim = min( minim , 1 + numOfElemFor[currElem - i*i] ) ;
            }
            numOfElemFor.push_back(minim) ;
        }
        return numOfElemFor[n] ;
    }
};
