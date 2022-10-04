#include<vector>
int m = 1e9+7 ;
long long int solveRec(int n, vector<int> &dp)
{
     if (n==1)
        return 0 ;
    if (n==2)
        return 1 ;
    if (dp[n]!=-1)
        return dp[n] ;
    
    return dp[n] = ( ((n-1)%m) *( ( (solveRec(n-1,dp))%m + (solveRec(n-2,dp))%m )%m ) )%m ;   
}
long long int countDerangements(int n) {
    vector<int> dp(n+1,-1) ;
    return solveRec(n,dp) ;