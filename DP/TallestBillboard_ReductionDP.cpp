class Solution {
    int minf = INT_MIN ;
    vector<vector<int> > dp;
    int solve(vector<int>& rods, int i, int diff){
        if (i==rods.size()){
            return (!diff)? 0:minf;
        }
        if (dp[i][diff+5000]!=-1)
            return dp[i][diff+5000] ;

        int inc = rods[i] + solve(rods,i+1,diff+rods[i]) ;
        int exc = solve(rods,i+1,diff-rods[i]) ;
        int dont = solve(rods,i+1,diff) ;

        return dp[i][diff+5000] = max({inc,exc,dont}) ;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        dp.resize(21,vector<int>(10001,-1)) ;
        return solve(rods,0,0) ;
    }
};
