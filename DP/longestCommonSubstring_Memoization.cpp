class Solution {
    int getAns(string &text1, int i, string &text2, int j, vector<vector<int>> &dp)
    {
        if (i==text1.length() || j==text2.length())
            return 0 ;
        if (dp[i][j]!=-1) return dp[i][j] ;
        
        if (text1[i]==text2[j]){
            return dp[i][j] = 1 + getAns(text1,i+1,text2,j+1,dp) ;
        }
        
        return dp[i][j] = max( getAns(text1,i,text2,j+1,dp) , getAns(text1,i+1,text2,j,dp) ) ;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length() ;
        vector<vector<int>> dp(n,vector<int>(m,-1)) ;
        return getAns(text1,0,text2,0,dp) ;
    }
};
