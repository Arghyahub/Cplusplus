class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n+1,vector<int>(2*k +1,0)) ;
        // return solve(prices,k,0,0,dp) ;
        
        for (int i=n-1; i>=0; i--){
            for (int oper=2*k-1; oper>=0 ; oper--){
                
                int profit = 0 ;
                if (!(oper&1) ){
                    int buyNow = -prices[i] + dp[i+1][oper+1] ;
                    int buyNext = dp[i+1][oper] ;
                    profit = max(buyNow,buyNext) ;
                }
                else{
                    int sellNow = prices[i] + dp[i+1][oper+1] ;
                    int sellNext = dp[i+1][oper] ;
                    profit=max(sellNow,sellNext) ;
                }
                dp[i][oper] =  profit ;
            }
        }
        return dp[0][0] ;
    }
};
