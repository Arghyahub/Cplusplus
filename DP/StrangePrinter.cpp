/*
we can look at atomic elements and ask how many prints they would require and add them up
Whenever after joining two elements they have the same start and end we would reduce 1 because
It can be printed in a single go
*/

class Solution {
    vector<vector<int>> dp;
    int solve(string &s, int i, int j){
        if (i>j) return 0;
        if (i==j) return 1;
        if (dp[i][j]!=-1)
            return dp[i][j] ;
        int ans = INT_MAX;
        for (int k=i; k<j; k++){
            ans = min(ans, solve(s,i,k) + solve(s,k+1,j) ) ;
        }
        if (s[i]==s[j]) ans--;
        return dp[i][j] = ans;
    }
public:
    int strangePrinter(string s) {
        dp.resize(101,vector<int>(101,-1)) ;
        // aaabbb can be formed by aaaaaa + bbb overlapping
        // aba can be formed by ab a or a ba => ab->2 , a->1 => merging subtract 1 because first and last is same
        return solve(s,0,s.size()-1) ;
    }
};