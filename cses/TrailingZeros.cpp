#include<iostream>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin>>n;

    ll fives = 0;
    ll mul = 5;

    while (mul<=n){
        fives+=n/mul;
        mul*=5;
    }

    cout<<fives;

    return 0;
}