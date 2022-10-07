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
        vector<bool> prev(total+1,false) ;
        vector<bool> curr(total+1,false) ;
        
        // 2. TRAVERSE IN THE SAME DP ARRAY APPLY ANALISED BASE CASE INTO
        // PREV BECAUSE IT SIGNIFIES DP[N-1]
        for (int s = 0 ; s<=total ; s++){
            if (s - nums[0] == 0)
                prev[s] = true;
        }
        
        // 3. TO FETCH DATA FROM DP[N-1] USE PREV, TO INSERT DATA INTO DP[N] USE CURR
        // AT THE END UPDATE PREV TO CURR
        
        for (int i=1; i<n; i++){
            for (int s=0; s<=total; s++){
                bool inc = false;
                if (s-nums[i]>=0)
                    inc = prev[s-nums[i]] ;
                bool exc = prev[s] ;
                
                curr[s] = (inc || exc) ;
            }
            prev = curr;
        }
        
        return prev[total] ;
        
    }
};
