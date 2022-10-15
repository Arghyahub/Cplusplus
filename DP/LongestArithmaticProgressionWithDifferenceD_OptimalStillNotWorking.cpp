class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size() ;
        if (n<=2) return n;
        
        vector<int> dp(n,0) ;
        int ans = 1 ;
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                int d = arr[j]-arr[i] ;
                if (d!=diff) continue;
                
                if (dp[i]==0){
                    dp[j] = 2 ;
                }
                else{
                    dp[j] = dp[i] + 1 ;
                }
                ans = max(ans,dp[j]) ;
            }
        }
        return ans;
    }
};
