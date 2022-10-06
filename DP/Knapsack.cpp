#include <bits/stdc++.h> 

int rec(vector<int> &w, vector<int> &v, int n, int maxw, int i, int currw)
{
    if (i>=n) return 0 ;
    int inc = 0, exc = 0 ;
    
    if (currw + w[i] <= maxw)
        inc = v[i] + rec(w,v,n,maxw,i+1,currw+w[i]) ;
    
    exc = rec(w,v,n,maxw,i+1,currw) ;
    return max(inc,exc) ;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return rec(weight,value,n,maxWeight,0,0) ;
}

//###############################################################################################################

#include <bits/stdc++.h> 

int rec(vector<int> &w, vector<int> &v, int n, int maxw, int i, int currw, vector<vector<int>> &dp)
{
    if (i>=n) return 0 ;
    if (dp[i][currw]!=-1) return dp[i][currw] ;
    
    int inc = 0, exc = 0 ;
    if (currw + w[i] <= maxw)
        inc = v[i] + rec(w,v,n,maxw,i+1,currw+w[i],dp) ;
    
    exc = rec(w,v,n,maxw,i+1,currw,dp) ;
    return dp[i][currw] = max(inc,exc) ;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)) ;
    return rec(weight,value,n,maxWeight,0,0,dp) ;
}