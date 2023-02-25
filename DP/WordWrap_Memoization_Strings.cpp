//User function Template for C++

class Solution {
    vector<vector<int>> dp;
    
    int solve(vector<int> &nums, int k, int i,int currline){
        if (i==nums.size())
            return 0;
        if (dp[i][currline]!=-1)
            return dp[i][currline] ;
        
        int inc,exc;
        inc = exc = INT_MAX ;
        if (currline==0 || currline+nums[i]+1<=k){ // If its the first element or the sum of width of two words + 1 space is <=k then only
            if (currline!=0) currline++;		// Add the space
            currline += nums[i] ;				// Add the New element
            
            inc = solve(nums,k,i+1,currline) ;
            
            currline -= nums[i] ;					// BackTrack
            if (currline!=0) currline-- ;
        }
        
        int space = k-currline;	
        if (currline!=0)				// How can we exclude if we haven't Included yet
            exc = space*space + solve(nums,k,i+1,nums[i]) ;
        
        return dp[i][currline] = min(inc,exc) ;
    }
public:
    int solveWordWrap(vector<int> &nums, int k) 
    {
        dp.resize(nums.size()+1,vector<int>(k+1,-1)) ;
        return solve(nums,k,0,0) ;
    } 
};
