class Solution {

public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size() ;
        vector<bool> up(m+1,0) ;
        vector<bool> down(m+1,0) ;

        up[0] = true; // base case 1

        for (int j=1; j<=m; j++){       // base case 2
            bool flag = true;
            for (int k=j-1; k>=0; k--){
                if (p[k]=='*')
                    k--;
                else{
                    up[j] = false;
                    flag=false;
                }
            }
            if (flag)
                up[j] = true;
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (s[i-1]==p[j-1] || p[j-1]=='.')
                    down[j] = up[j-1] ;
                else if (p[j-1]=='*'){
                    bool check=false;
                    if (s[i-1]==p[j-2] || p[j-2]=='.')
                        check = up[j] ; 
                    down[j] = ( down[j-2] || check ) ;
                }
                else
                    down[j] = false;
            }
            up=down;
        }

        return up[m] ;

    }
};