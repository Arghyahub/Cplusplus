class Solution {
public:
    bool isMatch(string &s, string &p) {
        int n = s.length() , m = p.length() ;
        vector<bool> rowU(m+1,0) ;
        vector<bool> rowL(m+1,0) ;
        
        rowU[0] = true;
        for (int j=1; j<=m; j++){
            bool check=true;
            for (int k=1; k<=j ; k++){
                if (p[k-1]!='*'){
                    check=false;
                    break;
                }
            }
            if (check) rowU[j] = true;
        }
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (s[i-1]==p[j-1] || p[j-1]=='?')
                    rowL[j] = rowU[j-1] ;
                else if (p[j-1]=='*')
                    rowL[j] = ( rowU[j] || rowL[j-1] ) ;
                else
                    rowL[j] = false;
            }
            rowU=rowL ;
        }
        return rowU[m] ;
    }
};
