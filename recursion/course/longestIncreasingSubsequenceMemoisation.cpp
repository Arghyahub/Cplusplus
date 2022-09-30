class Solution {
    int getSubs(vector<int> &nums, int index, int prev_i,vector<vector<int>> &dp )
    {
        if (index>=nums.size()){
            return 0 ;
        }
        
        if( dp[index][prev_i+1]!=-1)
            return dp[index][prev_i+1] ;
        
        
        // include if greater
        int include = 0 ;
        if ( prev_i ==-1 || nums[index] > nums[prev_i] )
            include = 1 + getSubs(nums,index+1,index,dp) ;
        
        // exclude
        int exclude = getSubs(nums,index+1,prev_i,dp) ;
        
        dp[index][prev_i+1] = max(include,exclude) ;
        return dp[index][prev_i+1] ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        /**
         * An element with index i will have hav
         * 
         */
        int n = nums.size() ;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1)) ;
        return getSubs(nums,0,-1,dp) ;
    }
};