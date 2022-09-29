class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,-1) ;
        int f = cost[0] ;
        int s = cost[1] ;
        
        for (int i=2; i<=n+1; i++){
            int c = (i<n)? cost[i]:0 ;
            int ans = min(f,s) + c ;
            f = s;
            s = ans ;
        }
        return s ;
    }
};