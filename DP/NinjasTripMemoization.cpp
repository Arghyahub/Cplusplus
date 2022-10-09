int solve(int n, vector<int> &arr, vector<int> &cost,int i, vector<int> &dp)
{
    if (i>=n)
        return 0 ;
    
    if (dp[i]!=-1) return dp[i] ;
    
    int index = i;
    
    // 1st case : 1 day cost
    int day = cost[0] + solve(n,arr,cost,i+1,dp) ;
    
    for (index = i; index<n && arr[index] < arr[i] + 7; index++ ) ;
    // 2nd case : 1 week
    int week = cost[1] + solve(n,arr,cost,index,dp) ;
    
    for (index = i; index<n && arr[index] < arr[i] + 30; index++ ) ;
    // 3rd case : 1 month
    int month = cost[2] + solve(n,arr,cost,index,dp) ;
    
    return dp[i] = min(day,min(week,month)) ;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,-1) ;
    return solve(n,days,cost,0,dp) ;
}
