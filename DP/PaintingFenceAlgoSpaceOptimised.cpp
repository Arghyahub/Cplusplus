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
    int f= k;
    int s= mul(k,k) ;
    
    for (int i=3; i<=n; i++){
        int ans = add( mul( s , k-1 ) , mul( f , k-1 ) ) ;
        f=s;
        s=ans ;
    }
    return s ;
}
