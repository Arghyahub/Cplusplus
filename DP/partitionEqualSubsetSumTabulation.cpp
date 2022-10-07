class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0 , n = nums.size();
        for (int i=0; i<n; i++)
            total+=nums[i] ;
        
        if (total&1) return false;
        total=total/2 ;
        
        // STEP 0. IF YOU SEE 2D DP, SOLVE THE LAST TEST CASE YOURSELF
        // IN MEMOIZATION
        
        // STEP 1. CREATE DP ARRAY
        vector<vector<bool>> dp(n,vector<bool>(total+1,false)) ;
        
        // STEP 2. ANALYSE BASE CASE
        for (int s = 0 ; s<=total ; s++){
            if (s - nums[0] == 0)
                dp[0][s] = true;
        }
        
        // STEP 3. TRAVERSE IN INDEX AND SUM AND UPDATE THE MEMOIZATION INTO TABULATION
        for (int i=1; i<n; i++){
            for (int s=0; s<=total; s++){
                bool inc = false;
                if (s-nums[i]>=0)
                    inc = dp[i-1][s-nums[i]] ;
                bool exc = dp[i-1][s] ;
                
                dp[i][s] = (inc || exc) ;
            }
        }
        
        return dp[n-1][total] ;
        
    }
};
