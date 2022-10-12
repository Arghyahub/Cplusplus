class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;
        vector<int> row1(n+1,0) ;
        vector<int> row2(n+1,0) ;
        // return solve(nums,0,n,-1,dp) ;
        
        for (int i=n-1; i>=0; i--){
            for (int iprev=i-1; iprev>=-1; iprev--){
                int inc=0;
                if (iprev==-1 || nums[iprev]<nums[i])
                    inc = 1 + row1[i+1] ;
                
                int exc = row1[iprev+1] ;
                row2[iprev+1] = max(inc,exc) ;
            }
            row1=row2 ;
        }
        
        return row2[0] ;
    }
};
