#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
#define ll long long

int main() {
    ll n, ans=0;
    ll prev = 0;
    cin>>n;
    for (int i=0; i<n; i++){
        ll curr;
        cin>>curr;

        ll diff = prev-curr;
        if (diff>0){
            ans+=diff;
            prev=curr+diff;
        }
        else {
            prev=curr;
        }
    }

    cout<<ans;
    

    return 0;
}

/*
3 2 5 1 7

*/