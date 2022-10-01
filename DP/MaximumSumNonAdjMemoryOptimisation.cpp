#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size() ;
    int f = nums[0] ;
    int s = max(nums[0],nums[1]) ;
    
    for (int i=2; i<n; i++)
    {
        int ans = max( nums[i] + f , s ) ;
        f=s;
        s=ans;
    }
    return s ;
}