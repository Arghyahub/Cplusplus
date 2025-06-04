#include<iostream>
using namespace std;
#define ll long long

int main() {
    int n, x=0;
    cin>>n;

    for (int i=1; i<=n; i++)
        x=x^i;
    
    for (int i=1; i<n; i++){
        int y;
        cin>>y;
        x = x^y;
    }

    cout<<x;

    return 0;
}