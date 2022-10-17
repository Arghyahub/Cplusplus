class Solution {
    int solve(vector<int>& prices, int k, int i, int oper,vector<vector<int>> &dp)
    {
        if (i==prices.size()) return 0 ;
        if (oper==2*k) return 0 ;
        
        if (dp[i][oper]!=-1) return dp[i][oper] ;
        
        int profit = 0 ;
        if (!(oper&1) ) {
            int buyNow = -prices[i] + solve(prices,k,i+1,oper+1,dp) ;
            int buyNext = solve(prices,k,i+1,oper,dp) ;
            profit = max(buyNow,buyNext) ;
        }
        else{
            int sellNow = prices[i] + solve(prices,k,i+1,oper+1,dp) ;
            int sellNext = solve(prices,k,i+1,oper,dp) ;
            profit=max(sellNow,sellNext) ;
        }
        return dp[i][oper] =  profit ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n,vector<int>(2*k,-1)) ;
        return solve(prices,k,0,0,dp) ;
    }
};
