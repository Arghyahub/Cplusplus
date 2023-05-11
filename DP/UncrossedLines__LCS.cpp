/**
 * Why LCS? , we can check condition to join , to skip , or to search in the direction
 * But How would the condition of crossing lines will be fixed?
 *      - LCS already has the condition of crossing lines fixed, we always go searching in one direction
 *      - And if the lines join, then we never go back
 *      - inshort: We are joining lines and never going back
*/
class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp, int i, int j){
        if (i==nums1.size() || j==nums2.size())
            return 0;
        if (dp[i][j]!=-1)
            return dp[i][j] ;
        
        int join = 0 , search = 0 , skip = 0;

        if (nums1[i]==nums2[j])
            join = 1 + solve(nums1,nums2,dp,i+1,j+1) ;

        skip = solve(nums1,nums2,dp,i+1,j) ;
        search = solve(nums1,nums2,dp,i,j+1) ; // search forward   

        return dp[i][j] = max({join,skip,search}) ;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size() , M = nums2.size() ;
        vector<vector<int>> dp(N,vector<int>(M,-1)) ;
        return solve(nums1,nums2,dp,0,0) ;
    }
};