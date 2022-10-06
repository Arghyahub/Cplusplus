#include <bits/stdc++.h>
int Tab(vector<int> &wt, vector<int> &v, int n, int maxw)
{
    // step 1. create dp array, index->0 to n-1 , weight->0 to maxm
    vector<int> prev(maxw+1,0) ;
    vector<int> curr(maxw+1,0) ;
    
    // step 2 : Analyse base case
    for (int w=wt[0]; w<=maxw; w++){ // only to run from 1st weight to heighest weight
        if (wt[0]<=maxw)    // IF THE WEIGHT OF 1ST ITEM IS IN THE LIMIT
            prev[w] = v[0] ;        // THEN THE FIRST ITEM'S VALUE SHOULD BE UPDATED
        else
            prev[w] = 0 ;
    }
    
    // Step 3 : traverse in index and weight
    for (int i=1; i<n; i++){
        for (int w=0; w<=maxw; w++){
            int inc = 0 , exc = 0 ;
            if (wt[i] <= w)
                inc = v[i] + prev[w-wt[i]] ;
            
            exc = prev[w] ; 
            
            curr[w] = max(inc,exc) ;
        }
        prev = curr ;
    }
    return prev[maxw] ;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return Tab(weight,value,n,maxWeight) ;
}
