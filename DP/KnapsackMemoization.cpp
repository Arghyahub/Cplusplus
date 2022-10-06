#include <bits/stdc++.h>

int Rec(vector<int> &w, vector<int> &v, int n, int maxw, int currw, vector<vector<int>> &dp)
{
    if (n<0){
        return 0 ;
    }
    
    if (dp[n][currw] != -1)
        return dp[n][currw] ;
    
    int inc=0 , exc = 0 ;
    if (currw + w[n] <= maxw)
        inc = v[n] + Rec(w,v,n-1,maxw,currw+w[n],dp) ;
    exc = Rec(w,v,n-1,maxw,currw,dp) ;
    
    return dp[n][currw] = max(inc,exc) ;
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)) ;
    return Rec(weight,value,n-1,maxWeight,0,dp) ;
}
