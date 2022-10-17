class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length() ;
        vector<int> rowL(m+1,0) ;
        vector<int> rowU(m+1,0) ;
        
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
        
                if (text1[i]==text2[j]){
                    rowU[j] = 1 + rowL[j+1] ;
                }
                else
                    rowU[j] = max( rowU[j+1] , rowL[j] ) ;
            }
            rowL=rowU ;
        }
        return rowU[0] ;
    }
};
