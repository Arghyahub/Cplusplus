#include <bits/stdc++.h> 
int solveRec(vector<int> &nums, int x)
{
    if (x==0)
        return 0 ;
    if (x < 0)
        return INT_MAX ;
    
    int mini = INT_MAX ;
    for (int i=0; i<nums.size(); i++){
        int ans = solveRec(nums,x-nums[i]) ;
        if (ans!=INT_MAX)
            mini = min(mini, 1 + ans) ;
    }
    return mini;
}

int minimumElements(vector<int> &nums, int x)
{
    int final = solveRec(nums,x) ;
    if (final==INT_MAX) return -1;
    
    return final;
}