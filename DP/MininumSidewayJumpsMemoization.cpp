class Solution {
    int solve(vector<int>& obstacles, int currlane, int pos,vector<vector<int>> &dp)
    {
        if (pos==obstacles.size()-1) return 0 ;
        
        if (dp[pos][currlane]!=-1) return dp[pos][currlane] ;
        
        if (obstacles[pos+1]!=currlane)
            return solve(obstacles,currlane,pos+1,dp) ;
        
        int ans = INT_MAX ;
        for (int lane=1; lane<=3; lane++){
            if (lane!=currlane && obstacles[pos]!=lane)
                ans = min(ans ,1 + solve(obstacles,lane,pos,dp) ) ;
        }
        return dp[pos][currlane] = ans;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() ;
        vector<vector<int>> dp(n,vector<int>(4,-1)) ;
        return solve(obstacles,2,0,dp) ;
    }
};
