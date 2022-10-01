#include<bits/stdc++.h> 

int sumRec(vector<int> &nums, int i, vector<int> &dp){
    if (i>=nums.size())
        return 0 ;
    
    if (dp[i]!=-1)
        return dp[i] ;
    
    // include
    int inc = nums[i] + sumRec(nums,i+2,dp) ;
    
    //exclude
    int exc = sumRec(nums,i+1,dp) ;
    
    return dp[i] = max(inc,exc) ;
}


int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),0) ;
    
    return sumRec(nums, 0,dp) ;
}