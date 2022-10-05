#include <bits/stdc++.h> 
#define m 1000000007
int add(long long int a, long long int b){
    return ((a%m) + (b%m))%m ;
}
int mul(long long int a, long long int b){
    return (a%m * b%m)%m ;
}

int numberOfWays(int n, int k) {
    vector<long long int> dp(n+1,0) ;
    dp[1] = k;
    dp[2] = mul(k,k) ;
    
    for (int i=3; i<=n; i++){
        dp[i] = add( mul( dp[i-1] , k-1 ) , mul( dp[i-2] , k-1 ) ) ;
    }
    return dp[n] ;
}
