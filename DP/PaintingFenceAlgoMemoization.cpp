#include <bits/stdc++.h> 
#define m 1000000007
int add(long long int a, long long int b){
    return ((a%m) + (b%m))%m ;
}
int mul(long long int a, long long int b){
    return (a%m * b%m)%m ;
}

long long int Tab(int n, int k,vector<long long int> &dp)
{
    if (n==1) return k;
    if (n==2) return mul(k,k) ;
    
    if (dp[n]!=-1)
        return dp[n] ;
    
    return dp[n] = add( mul(Tab(n-2,k,dp),k-1) , mul(Tab(n-1,k,dp),k-1)  ) ;
}

int numberOfWays(int n, int k) {
    vector<long long int> dp(n+1,-1) ;
    return Tab(n,k,dp) ;
}
