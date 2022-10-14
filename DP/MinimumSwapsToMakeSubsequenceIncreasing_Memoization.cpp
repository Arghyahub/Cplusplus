class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped,vector<vector<int>> &dp)
    {
        if (i>=nums1.size()) return 0 ;
        if (dp[i][swapped]!=-1) return dp[i][swapped] ;
        
        int prev1 = nums1[i-1] ;
        int prev2 = nums2[i-1] ;
        
        if (swapped)
            swap(prev1,prev2) ;
        
        int ans = INT_MAX ;
        if (nums1[i]>prev1 && nums2[i]>prev2)
            ans = solve(nums1,nums2,i+1,false,dp) ;
        if (nums1[i]>prev2 && nums2[i]>prev1)
            ans = min(ans , 1 + solve(nums1,nums2,i+1,true,dp) ) ;
        
        return dp[i][swapped] = ans ;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1) ;
        nums2.insert(nums2.begin(),-1) ;
        vector<vector<int>> dp(nums1.size(),vector<int>(2,-1)) ;
        bool swapped=false;
        return solve(nums1,nums2,1,swapped,dp) ;
    }
};
