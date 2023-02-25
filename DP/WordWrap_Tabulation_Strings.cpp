
class Solution {
    vector<vector<int>> dp;
public:
    int solveWordWrap(vector<int> &nums, int k) 
    {
        int n = nums.size() , inc,exc ;
        dp.resize(n+1,vector<int>(k+1,INT_MAX)) ;
        
        for (int i=0; i<=k; i++)
            dp[n][i] = 0 ;
        
        for (int i=n-1; i>=0; i--){
            for (int currline=k; currline>=0; currline--){
                
                inc = exc = INT_MAX ;
                if (currline==0 || currline+nums[i]+1<=k){
                    if (currline!=0) currline++;
                    currline += nums[i] ;
                    
                    inc = dp[i+1][currline] ;
                    
                    currline -= nums[i] ;
                    if (currline!=0) currline-- ;
                }
                
                int space = k-currline;
                if (currline!=0)
                    exc = space*space + dp[i+1][nums[i]] ;
                
                dp[i][currline] = min(inc,exc) ;
            }
        }
        return dp[0][0] ;
    } 
};
