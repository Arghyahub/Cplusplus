class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        if (n==1) return 0 ;
        vector<vector<int>> dp(n+1,vector<int>(2,0)) ;
        // return solve(prices,0,1,dp) ;
        
        for (int i=n-1; i>=0; i--){
            for (int buy=0; buy<=1; buy++){
                int diff=INT_MIN;
                if (buy){
                    int buyNow = -prices[i] + dp[i+1][0] ;
                    int buyNext = dp[i+1][1] ;
                    diff= max(buyNow,buyNext) ;
                }
                else{
                    int sellNow = prices[i] + dp[i+1][1] ;
                    int sellNext = dp[i+1][0] ;
                    diff=max(sellNow,sellNext) ;
                }
                dp[i][buy] = diff;
            }
        }
        return dp[0][1] ;
    }
};
