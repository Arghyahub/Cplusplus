class Solution {
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& piles, int k, int i){
        if (k==0) return 0;
        if (i>=piles.size()) return INT_MIN;
        if (dp[k][i]!=-1)
            return dp[k][i] ;

        int res = solve(piles,k,i+1) ; // skip curr

        int sum = 0;
        for (int j=0; j<min(k,(int)piles[i].size()); j++){
            sum+= piles[i][j] ;
            res = max(res, sum + solve(piles, k - (j+1) , i+1) ) ;
        }

        return dp[k][i] = res;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize(k+1,vector<int>(piles.size()+1,-1)) ;
        return solve(piles,k,0) ;
    }
};
