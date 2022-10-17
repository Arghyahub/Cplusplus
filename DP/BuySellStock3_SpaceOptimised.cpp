class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size() ;
        vector<vector<int>> rowL(2,vector<int>(3,0)) ;
        vector<vector<int>> rowU(2,vector<int>(3,0)) ;
        
        for (int i=size-1; i>=0; i--){
            for (int buy=0; buy<=1; buy++){
                for (int n=1; n<=2; n++){
                    int ans = INT_MIN ;
                    if (buy){
                        int buyNow = -prices[i] + rowL[0][n] ;
                        int buyNext = rowL[1][n] ;
                        ans=max(buyNow,buyNext) ;
                    }
                    else{
                        int sellNow = prices[i] + rowL[1][n-1] ;
                        int sellNext = rowL[0][n] ;
                        ans = max(sellNow,sellNext) ;
                    }
                    rowU[buy][n] = ans ;
                }
            }
            rowL = rowU ;
        }
        return rowU[1][2] ;
    }
};
