#include <bits/stdc++.h> 
#define m 1000000009
int add(long long int a, long long int b){
    return (a%m + b%m)%m ;
}
int mul(long long int a, long long int b){
    return (a%m * b%m)%m ;
}

long long int Rec(int n, int k)
{
    if (n==1) return k;
    if (n==2) return mul(k,k) ;
    
    return add( mul(Rec(n-2,k),k-1) , mul(Rec(n-1,k),k-1)  ) ;
}

int numberOfWays(int n, int k) {
    return Rec(n,k) ;
}