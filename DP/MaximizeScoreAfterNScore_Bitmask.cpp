class Solution {
    int solve(vector<int>& nums,unordered_map<int,int> &dp , int mask, int mul){
        int N = nums.size()  , ans = 0;
        if (dp.count(mask))
            return dp[mask] ;

        for (int i=0; i<N; i++){
            if ( (mask>>i)&1 ) continue;    // which are not masked skip them
            for (int j=i+1; j<N; j++){
                if ( (mask>>j)&1 ) continue;

                int newmask = mask | (1<<i) | (1<<j) ;
                int gc = (__gcd(nums[i] , nums[j]) )* mul ;
                int newans = gc + solve(nums, dp ,newmask,mul+1) ;

                ans = max(ans,newans) ;
            }
        }
        return dp[mask] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        unordered_map<int,int> dp;
        return solve(nums,dp,0,1) ;
    }
};
