#include<iostream>
using namespace std;

void solve(long long x, long long y){
    if (x==0 && y==0) {
        cout<<1<<" ";
        return;
    }
    long long mx = max(x,y);
    bool down = mx&1 ? true:false;
    long long base[2] = {0,0};
    if (down) base[1] = mx;
    else base[0] = mx;

    long long val = mx*mx + 1 + abs(base[0]-x) + abs(base[1]-y);
    cout<<val<<" ";
}

int main() {
    long long n;
    cin>>n;

    while (n--){
        long long x,y;
        cin>>x>>y;
        solve(x-1,y-1);
    }
    return 0;
}

/*

*/