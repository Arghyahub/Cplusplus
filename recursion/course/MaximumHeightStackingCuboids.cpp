class Solution {
    bool check(vector<vector<int>>& cub,int curr, int prev)
    {
        if (cub[curr][0]<=cub[prev][0] && cub[curr][1]<=cub[prev][1] &&
        cub[curr][2]<=cub[prev][2])
            return true;
        return false;
    }

    int solve(vector<vector<int>>& cuboids,int i, int prev, vector<vector<int>> &dp)
    {
        if (i==-1)
            return 0 ;
        
        if (dp[i][prev+1]!=-1)
            return dp[i][prev+1] ;
        
        int pick=0 ;
        if (prev==-1 || check(cuboids,i,prev))
            pick = cuboids[i][2] + solve(cuboids,i-1,i,dp) ;
        int dontpick = solve(cuboids,i-1,prev,dp) ;

        return dp[i][prev+1] = max(pick,dontpick) ;
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size() ;
        for (int i=0; i<n; i++)
            sort(cuboids[i].begin(),cuboids[i].end()) ;
        sort(cuboids.begin(),cuboids.end()) ;
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1)) ;
        return solve(cuboids,n-1,-1,dp) ;
    }
};
