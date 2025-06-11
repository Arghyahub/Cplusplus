#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
#define ll long long

int main() {
    int t;
    cin>>t;

    cout<<"0\n";

    if (t>1) cout<<"6\n";
    if (t>2) cout<<"28\n";

    ll mul = 3;
    ll add = 3;

    for (ll i=4; i<=t; i++){
        ll n = i*i;
        ll perm = (n*(n-1))/2;

        ll sub = 8*mul;
        ll ans = perm-sub;

        cout<<ans<<"\n";
        mul=mul+add;
        add++;
    }

    return 0;
}