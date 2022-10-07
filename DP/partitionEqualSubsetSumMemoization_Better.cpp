class Solution {
    bool solve(vector<int>& nums, int i, int total,vector<vector<int>> &dp)
    {
        if (total<0) return false;
        if (i==0){
            if (total - nums[i] == 0)
                return true;
            return false;
        }
        
        if (dp[i][total]!=-1) return dp[i][total] ;
        
        //inc
        bool inc = solve(nums,i-1,total - nums[i],dp) ;
        
        //exc
        bool exc = solve(nums,i-1,total,dp) ;
        
        return dp[i][total] = (inc || exc) ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total = 0 , n = nums.size();
        for (int i=0; i<n; i++)
            total+=nums[i] ;
        
        if (total&1) return false;          // IF THE SUM IS ODD , WE CANNOT DIVIDE IT INTO TWO EQUAL SUBSETS
        total=total/2 ;
        
        vector<vector<int>> dp(n,vector<int>(total+1,-1)) ;     // CHECK FROM Nth INDEX AND FULL CAPACITY
        
        return solve(nums,n-1,total,dp) ;
    }
};