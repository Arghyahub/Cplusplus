int solve(int n, vector<int> &arr, vector<int> &cost,int i)
{
    if (i>=n)
        return 0 ;
    
    int index = i;
    
    // 1st case : 1 day cost
    int day = cost[0] + solve(n,arr,cost,i+1) ;
    
    for (index = i; index<n && arr[index] < arr[i] + 7; index++ ) ;
    // 2nd case : 1 week
    int week = cost[1] + solve(n,arr,cost,index) ;
    
    for (index = i; index<n && arr[index] < arr[i] + 30; index++ ) ;
    // 3rd case : 1 month
    int month = cost[2] + solve(n,arr,cost,index) ;
    
    return min(day,min(week,month)) ;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n,days,cost,0) ;
}
