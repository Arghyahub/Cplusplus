class Solution {
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>> &dp)
    {
        if (i==prices.size()) return 0 ;
        
        if (dp[i][buy]!=-1) return dp[i][buy] ;
        
        int diff=INT_MIN;
        
        if (buy){
            int buyNow = -prices[i] + solve(prices,i+1,0,dp) ;
            int buyNext = solve(prices,i+1,1,dp) ;
            diff= max(buyNow,buyNext) ;
        }
        else
        {
            int sellNow = prices[i] + solve(prices,i+1,1,dp) ;
            int sellNext = solve(prices,i+1,0,dp) ;
            diff=max(sellNow,sellNext) ;
        }
        return dp[i][buy] = diff;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        if (n==1) return 0 ;
        vector<vector<int>> dp(n,vector<int>(2,-1)) ;
        return solve(prices,0,1,dp) ;
    }
};
