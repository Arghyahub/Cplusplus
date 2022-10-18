class Solution {
public:
    int minDistance(string &word1, string &word2) {
        if (word1.length()==0) return word2.length() ;
        if (word2.length()==0) return word1.length() ;
        int n = word1.size() , m=word2.size() ;
        
        vector<int> rowL(m+1) ;
        vector<int> rowU(m+1) ;
        
        for (int j=0; j<=m; j++)
            rowL[j] = m - j;
        
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                rowU[m] = n-i ;
                int ans = 0 ;
                if (word1[i]==word2[j])
                    ans = rowL[j+1] ;
                else{
                    // insert
                    int insAns = 1 + rowU[j+1] ;
                    // delete
                    int delAns = 1 + rowL[j] ;
                    // replace
                    int repAns = 1 + rowL[j+1] ;
                    ans=min(insAns,min(delAns,repAns) ) ;
                }
                rowU[j] = ans;
            }
            rowL=rowU ;
        }
        return rowU[0] ;
    }
};
