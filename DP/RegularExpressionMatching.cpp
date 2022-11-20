class Solution {
    bool solve(string &s, string &p, int i, int j,vector<vector<int>> &dp)
    {
        if (i<0 && j<0) { 
            return true;
        }
        else if ( j<0 ) return false;
        else if (i<0){
            for (int k=j; k>=0; k--){
                if (p[k]=='*')	// IF A CHARACTER IS * WE CAN SKIP THE PREVIOUS CHARACTER
                    k--;
                else
                    return false;
            }
            return true;
        }

        if (dp[i][j]!=-1)
            return dp[i][j] ;
        

        if (s[i]==p[j] || p[j]=='.')
            return dp[i][j] = solve(s,p,i-1,j-1,dp) ;
        
        else if (p[j]=='*'){
            bool check=false;
            if (s[i]==p[j-1] || p[j-1]=='.')	// IF THE PREVIOUS MATCHES WITH CURRENT I, WE CAN BUILD UP A STRING, EX: C* => C OR CC OR CCC ....
                check = solve(s,p,i-1,j,dp) ;
            return dp[i][j] = ( solve(s,p,i,j-2,dp) || check ) ;	// OR WE CAN SKIP EMPTY STRINGS
        }
        //else
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1)) ;
        return solve(s,p,s.size()-1,p.size()-1,dp) ;
    }
};
