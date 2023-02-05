#include<bits/stdc++.h>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

void solve(int n, string &s){
    if (n==1){
        cout<<1<<nl;
        return;
    }

    
    int i=0, j=n-1;
    // cout<<s[i]<<s[j]<<'-';
    while (i<j){
        if (s[i]=='0' && s[j]=='1'){
            i++;
            j--;
            // cout<<'.' ;
        }
        else if(s[i]=='1' && s[j]=='0'){
            i++;
            j--;
            // cout<<',' ;
        }
        else
            break;
    }
    if (i==j){
        cout<<1<<nl;
        return;
    }
    if (i>j){
        cout<<0<<nl;
        return;
    }
    // cout<<"itran ";
    cout<<j-i+1<<nl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        // cout<<s<<"  ";
        solve(n,s) ;
    }
    return 0;
}