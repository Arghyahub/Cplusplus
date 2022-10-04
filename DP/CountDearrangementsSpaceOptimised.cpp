#include<vector>
long long int countDerangements(int n) {
    int m = 1e9+7 ;
    vector<long long int> dp(n+1,0) ;
    long long int f = 0 ;
    long long int s = 1 ;
    for (int i=3; i<=n; i++){
        int ans = ( ((i-1)%m) * ( ( (s%m) + (f%m) )%m) )%m ;
        f=s;
        s=ans ;
    }
    return s ;
}
