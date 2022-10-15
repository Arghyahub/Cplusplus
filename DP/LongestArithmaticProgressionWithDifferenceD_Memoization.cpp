class Solution {
    int getAns(vector<int>& arr, int diff,int prev_i, int i,vector<vector<int>> &dp)
    {
        if (i==arr.size()){
            return 0 ;
        }
        
        if (dp[i][prev_i+1]!=-1) return dp[i][prev_i+1] ;
        
        int inc=0 , exc ;
        
        if (prev_i==-1 || (arr[i]-arr[prev_i]) == diff){
            inc = 1 + getAns(arr,diff,i,i+1,dp) ;
        }
        
        exc = getAns(arr,diff,prev_i,i+1,dp) ;
        
        return dp[i][prev_i+1] = max(inc,exc) ;
    }
    
    
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size() ;
        vector<vector<int>> dp(n,vector<int>(n+1,-1)) ;
        return getAns(arr,difference,-1,0,dp) ;
    }
};
