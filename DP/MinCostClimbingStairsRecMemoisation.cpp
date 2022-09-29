class Solution {
    int getans(vector<int>& cost, int s,int n,vector<int> &dp)
    {
        if (s==n)
            return 0 ;
        
        if (s > n)
            return -1 ;
        
        if (dp[s+1]!=-1)
            return dp[s+1] ;
        
        int c = (s>=0)? cost[s]:0 ;
        
        int ones = getans(cost,s+1,n,dp) ;
        int twos = getans(cost,s+2,n,dp) ;
        
        if (ones==-1 && twos!=-1) dp[s+1] = twos+c ;
        if (ones!=-1 && twos==-1) dp[s+1] = ones+c ;
        else dp[s+1] = min(ones,twos) + c ;
        
        return dp[s+1] ;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,-1) ;
        
        return getans(cost,-1,n,dp) ;
    }
};