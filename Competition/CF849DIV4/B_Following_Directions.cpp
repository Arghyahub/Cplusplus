#include<bits/stdc++.h>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

void solve(int n, string &s){
    int x=0 , y=0;
    for (auto ch : s){
        if (ch=='U')
            y++;
        else if (ch=='D')
            y--;
        else if (ch=='L')
            x--;
        else
            x++;
        if (x==1 && y==1){
            yes;
            return;
        }
    }
    no;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s) ;
    }
    return 0;
}