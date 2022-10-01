#include <bits/stdc++.h> 

int sumRec(vector<int> &nums, int i){
    if (i>=nums.size())
        return 0 ;
    
    // include
    int inc = nums[i] + sumRec(nums,i+2) ;
    
    //exclude
    int exc = sumRec(nums,i+1) ;
    
    return max(inc,exc) ;
}


int maximumNonAdjacentSum(vector<int> &nums){
    return sumRec(nums, 0) ;
}