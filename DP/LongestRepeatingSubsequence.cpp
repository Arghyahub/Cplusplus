class Solution {
    
    vector<vector<int>> dp;
    
    int solve(string &str, int i, int j){
        if (i==str.size() || j==str.size())
            return 0;
            
        if (dp[i][j]!=-1)
            return dp[i][j] ;
        int ans = 0;
        if (i!=j && str[i]==str[j])
            ans = 1 + solve(str,i+1,j+1) ;
        else{
            int exc1 = solve(str,i+1,j) ;
            int exc2 = solve(str,i,j+1) ;
            ans=max({ans,exc1,exc2}) ;
        }
        
        return dp[i][j] = ans;
    }
    
	public:
		int LongestRepeatingSubsequence(string &str){
		    dp.resize(str.size()+1,vector<int>(str.size()+1,-1)) ;
		    return solve(str,0,0) ;
		}

};
