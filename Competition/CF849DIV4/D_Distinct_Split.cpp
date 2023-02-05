#include<bits/stdc++.h>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

void solve(int n, string &s){
    unordered_map<char,int> right;
    unordered_map<char,int> left;
    for (auto ch : s)
        left[ch]++;

    int ans=0;
    for (auto ch : s){
        int a=0,b=0;
        left[ch]--;
        right[ch]++;
        for (auto it : left)
            if (it.second!=0)
                a++;
        for (auto it : right)
            if (it.second!=0)
                b++;
        ans=max(ans,a+b) ;
    }
    cout<<ans<<nl;
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