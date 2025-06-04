#include<iostream>
#include<math.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin>>s;
    ll mx = 0, l=0;

    for (ll r=0; r<s.length(); r++) {
        if (s[l]!=s[r]){
            ll len = r-l;
            mx = max(mx,len);
            l=r;
        }
    }

    ll comp = s.length() - l;
    mx = max(mx,comp);
    
    cout<<mx;
    

    return 0;
}