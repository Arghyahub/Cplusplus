class Solution {
    int solve(vector<int>& nums, int i, int n, int iprev, vector<vector<int>>  &dp)
    {
        if (i==n) return 0 ;
        
        if (dp[i][iprev+1]!=-1) return dp[i][iprev+1] ;
        
        int inc=0 ;
        if (iprev==-1 || nums[iprev]<nums[i])
            inc = 1 + solve(nums,i+1,n,i,dp) ;
        int exc = solve(nums,i+1,n,iprev,dp) ;
        return dp[i][iprev+1] = max(inc,exc) ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n,vector<int>(n,-1)) ;
        return solve(nums,0,n,-1,dp) ;
    }
};
