#include<bits/stdc++.h>
using namespace std;

int main() {
    int N = 100;

    vector<bool> sieve(N+1,true);
    sieve[0] = false;
    sieve[1] = false;

    for (int i=2; i<=N; i++){
        if (!sieve[i]) continue;
        for (int j=2; i*j<=N; j++)
            sieve[i*j] = false;
    }

    cout<<"All Prime Number\n";

    for (int i=0; i<=N; i++)
        if (sieve[i])
            cout<<i<<" ";

    return 0;
}