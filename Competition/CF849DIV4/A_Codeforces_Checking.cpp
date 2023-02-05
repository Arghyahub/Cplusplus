#include<bits/stdc++.h>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

void solve(int n){

}

int main(){
    int t;
    cin>>t;
    unordered_map<char,bool> mp;
    mp['c'] = true;
    mp['o'] = true;
    mp['d'] = true;
    mp['e'] = true;
    mp['f'] = true;
    mp['o'] = true;
    mp['r'] = true;
    mp['e'] = true;
    mp['s'] = true;
    while(t--){
        char c;
        cin>>c;
        if (mp.count(c))
            yes;
        else
            no;
    }
    return 0;
}