class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        if (n==1) return 0 ;
        vector<int> small(n) ;
        small[0] = prices[0] ;
        for (int i=1; i<n; i++ )
            small[i] = min(small[i-1],prices[i]) ;
        
        int ans = 0 ;
        for (int i=0; i<n; i++)
            ans=max(ans,prices[i]-small[i]) ;
        return ans;
    }
};
