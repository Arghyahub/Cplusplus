class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size() ;
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(2,vector<int>(3,0))) ;
        // return solve(prices,0,1,2,dp) ;
        
        for (int i=size-1; i>=0; i--){
            for (int buy=0; buy<=1; buy++){
                for (int n=1; n<=2; n++){
                    int ans = INT_MIN ;
                    if (buy){
                        int buyNow = -prices[i] + dp[i+1][0][n] ;
                        int buyNext = dp[i+1][1][n] ;
                        ans=max(buyNow,buyNext) ;
                    }
                    else{
                        int sellNow = prices[i] + dp[i+1][1][n-1] ;
                        int sellNext = dp[i+1][0][n] ;
                        ans = max(sellNow,sellNext) ;
                    }
                    dp[i][buy][n] = ans ;
                }
            }
        }
        return dp[0][1][2] ;
    }
};
