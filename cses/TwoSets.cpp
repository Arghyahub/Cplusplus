#include<iostream>
#include <unordered_map>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin>>n;

    ll sum = n*(n+1)/2;

    if (sum&1)cout<<"NO";
    else {
        cout<<"YES\n";
        unordered_map<ll,bool> mp;
        ll deduct = (sum/2), curr = n;
        while (deduct > 0){
            while (curr>deduct) curr--;
            deduct-=curr;
            mp[curr] = true;
            curr--;
        }

        cout<<mp.size()<<"\n";
        for (auto pq : mp){
            cout<<pq.first<<" ";
        }
        cout<<"\n";
        cout<<(n-mp.size())<<"\n";
        for (ll i=1; i<=n; i++){
            if (mp.count(i)==0)
                cout<<i<<" ";
        }
    }

    return 0;
}