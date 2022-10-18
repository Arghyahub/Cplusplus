class Solution {
    int solve(string &word1, string &word2, int i, int j,vector<vector<int>> &dp)
    {
        if (i == word1.length())
            return word2.length() - j ;
        if (j==word2.length())
            return word1.length() - i ;
        
        if (dp[i][j]!=-1) return dp[i][j] ;
        
        int ans = 0 ;
        if (word1[i]==word2[j])
            return 0 + solve(word1,word2,i+1, j+1,dp) ;
        else{
            // insert
            int insAns = 1 + solve(word1,word2,i,j+1,dp) ;
            // delete
            int delAns = 1 + solve(word1,word2,i+1,j,dp) ;
            // replace
            int repAns = 1 + solve(word1,word2,i+1,j+1,dp) ;
            ans=min(insAns,min(delAns,repAns) ) ;
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string &word1, string &word2) {
        int n = word1.size() , m = word2.size() ;
        vector<vector<int>> dp(n,vector<int>(m,-1)) ;
        return solve(word1,word2,0,0,dp) ;
    }
};
