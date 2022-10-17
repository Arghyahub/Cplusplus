class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        if (n==1) return 0 ;
        vector<int> lRow(2);
        vector<int> uRow(2);
        
        for (int i=n-1; i>=0; i--){
            for (int buy=0; buy<=1; buy++){
                int diff=INT_MIN;
                if (buy){
                    int buyNow = -prices[i] + lRow[0] ;
                    int buyNext = lRow[1] ;
                    diff= max(buyNow,buyNext) ;
                }
                else{
                    int sellNow = prices[i] + lRow[1] ;
                    int sellNext = lRow[0] ;
                    diff=max(sellNow,sellNext) ;
                }
                uRow[buy] = diff;
            }
            lRow=uRow ;
        }
        return uRow[1] ;
    }
};
