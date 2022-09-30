#include <bits/stdc++.h> 
int solveMem(vector<int> &nums, int x,vector<int> &dp)
{
    if (x==0)
        return 0 ;
    if (x < 0)
        return INT_MAX ;
    
    if (dp[x]!=-1)
        return dp[x] ;
    
    int mini = INT_MAX ;
    for (int i=0; i<nums.size(); i++){
        int ans = solveMem(nums,x-nums[i],dp) ;
        if (ans!=INT_MAX)
            mini = min(mini, 1 + ans) ;
    }
    return dp[x] = mini;
}

int minimumElements(vector<int> &nums, int x)
{
    vector<int> dp(x+1,-1) ;
    int final = solveMem(nums,x,dp) ;
    if (final==INT_MAX) return -1;
    
    return final;
}