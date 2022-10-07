class Solution {
    bool solve(vector<int>& nums, int i, int total,int sum,vector<vector<int>> &dp)
    {
        if (i==0){
            sum+=nums[i] ;
            if (total-sum == sum)
                return true;
            return false;
        }
        
        if (dp[i][sum]!=-1) return dp[i][sum] ;
        
        //inc
        bool inc = solve(nums,i-1,total,sum+nums[i],dp) ;
        
        //exc
        bool exc = solve(nums,i-1,total,sum,dp) ;
        
        return dp[i][sum] = (inc || exc) ;
    }


public:
    bool canPartition(vector<int>& nums) {
        int total = 0 , n = nums.size();
        for (int i=0; i<n; i++)
            total+=nums[i] ;
        
        vector<vector<int>> dp(n,vector<int>(total,-1)) ;
        
        return solve(nums,n-1,total,0,dp) ;
    }
};
