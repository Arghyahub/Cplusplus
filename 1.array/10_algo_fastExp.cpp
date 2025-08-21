#include<bits/stdc++.h>
using namespace std;

int Power(int base, int power) {
    if (power <= 1) return base;
    else if (power&1) return base * Power(base,power-1);
    else{
        int halfPow = Power(base,power/2);
        return halfPow * halfPow;
    }
}

int main() {
    int ans = Power(2,3);
    cout<<ans<<endl;

    ans = Power(2,4);
    cout<<ans;
    return 0;
}