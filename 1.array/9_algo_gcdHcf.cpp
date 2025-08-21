#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    int a = 4, b = 16;
    int c = gcd(a,b);
    cout<<c<<endl;
    int lcm = a*b/(gcd(a,b));
    cout<<lcm<<endl;
    return 0;
}