class Solution {
    int solve(vector<int>& prices, int i, int buy, int n, vector<vector<vector<int>>> &dp)
    {
        if (i==prices.size()) return 0 ;
        if (n==0) return 0 ;
        
        if (dp[i][buy][n]!=-1) return dp[i][buy][n] ;
        
        int ans = INT_MIN ;
        
        if (buy){
            int buyNow = -prices[i] + solve(prices,i+1,0,n,dp) ;
            int buyNext = solve(prices,i+1,1,n,dp) ;
            ans=max(buyNow,buyNext) ;
        }
        else{
            int sellNow = prices[i] + solve(prices,i+1,1,n-1,dp) ;
            int sellNext = solve(prices,i+1,0,n,dp) ;
            ans = max(sellNow,sellNext) ;
        }
        return dp[i][buy][n] = ans ;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1))) ;
        return solve(prices,0,1,2,dp) ;
    }
};
