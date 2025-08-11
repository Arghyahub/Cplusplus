#include<iostream>
#include<math.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin>>t;

    while (t--){
        ll p,q;
        cin>>p>>q;

        ll threeM = 2*q-p;
        if (threeM%3!=0 || threeM<0) cout<<"NO\n";
        else {
            ll threeN = 2*p - q;
            if (threeN%3!=0 || threeN<0) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }

    return 0;
}

/*
p=2n+m
q=n+2m

  p= 2n+ m
-2q=-2n-4m
p-2q=-3m
3m=2q-p

3p=6n+2q-p
4p=6n+2q
2p=3n+q
3n=2p-q
*/