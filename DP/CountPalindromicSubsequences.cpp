class Solution{
    int m=1e9+7 ;
    vector<vector<long long int>> dp;
    long long int fn(string &s, int i, int j){
        if (i==j) return 1;
        if (i>j) return 0;
        
        if (dp[i][j]!=-1) return dp[i][j] ;
        if (s[i]==s[j])
            dp[i][j] = (fn(s,i+1,j) + fn(s,i,j-1) + 1)%m ; 	// Add 1 for emtpy subsequence
        else
            dp[i][j] = ((fn(s,i+1,j) + fn(s,i,j-1) - fn(s,i+1,j-1))%m + m)%m ; // Subtract the repeated part
        return dp[i][j] ;
    }
    
    public:
    /*You are required to complete below method */
    long long int  countPS(string &str)
    {
        int n = str.size();
        dp.resize(n+1,vector<long long int>(n+1,-1)) ;
        return fn(str,0,n-1) ;
    }
     
};
