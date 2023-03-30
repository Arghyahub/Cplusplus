class Solution {
    unordered_map<string,bool> dp;
    bool solve(string s1, string s2){
        if (s1==s2)
            return true;
        
        string tmp = s1 + '*' + s2;	//	To hash different strings
        if (dp.count(tmp))
            return dp[tmp] ;
        
        int n = s1.size() ;
        
        for (int i=1; i<n; i++){
            if(solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i)) )	// Check same parts
                return dp[tmp] = true;
            if (solve(s1.substr(0,i),s2.substr(n-i)) && solve(s1.substr(i),s2.substr(0,n-i)))	// Check alternate parts
                return dp[tmp] = true;
        }
        return dp[tmp] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        return solve(s1,s2) ;
    }
};
