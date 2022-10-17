class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        if (n==1) return 0 ;
        int prev = prices[0] ;
        
        int ans = 0 , curr;
        for (int i=1; i<n; i++ ){
            curr = min(prev,prices[i]) ;
            ans=max(ans,prices[i]-curr) ;
            prev=curr ;
        }
        
        return ans;
    }
};
