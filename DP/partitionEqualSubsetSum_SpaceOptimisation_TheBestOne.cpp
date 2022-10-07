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
        vector<bool> dp(total+1,false) ;
        
        for (int s = 0 ; s<=total ; s++){
            if (s - nums[0] == 0)
                dp[s] = true;
        }
        
        // TRAVERSE IN OPPOSITE DIRECTION SO YOU DON'T LOSE THE THE TRACK OF PREVIOUS ELEMENTS
        for (int i=1; i<n; i++){
            for (int s=total; s>=0; s--){
                bool inc = false;
                if (s-nums[i]>=0)
                    inc = dp[s-nums[i]] ;
                bool exc = dp[s] ;
                
                dp[s] = (inc || exc) ;
            }
        }
        
        return dp[total] ;
        
    }
};
