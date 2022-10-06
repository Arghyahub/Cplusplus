#include <bits/stdc++.h>
int Tab(vector<int> &wt, vector<int> &v, int n, int maxw)
{
    // step 1. create dp array, index->0 to n-1 , weight->0 to maxm
    vector<vector<int>> dp(n,vector<int>(maxw+1,0)) ;
    
    // step 2 : Analyse base case
    for (int w=wt[0]; w<=maxw; w++){ // only to run from 1st weight to heighest weight
        if (wt[0]<=maxw)    // IF THE WEIGHT OF 1ST ITEM IS IN THE LIMIT
            dp[0][w] = v[0] ;        // THEN THE FIRST ITEM'S VALUE SHOULD BE UPDATED
        else
            dp[0][w] = 0 ;
    }
    
    // Step 3 : traverse in index and weight
    for (int i=1; i<n; i++){
        for (int w=0; w<=maxw; w++){
            int inc = 0 , exc = 0 ;
            if (wt[i] <= w)
                inc = v[i] + dp[i-1][w-wt[i]] ;
            
            exc = dp[i-1][w] ; 
            
            dp[i][w] = max(inc,exc) ;
        }
    }
    return dp[n-1][maxw] ;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return Tab(weight,value,n,maxWeight) ;
}
