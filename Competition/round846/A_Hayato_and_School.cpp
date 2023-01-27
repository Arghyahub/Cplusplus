#include<iostream>
#include<vector>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

void solve(int n, int *arr){
    vector<int> odd;
    vector<int> even;
    for (int i=0; i<n; i++){
        if (arr[i]&1) odd.push_back(i) ;
        else even.push_back(i) ;
    }
    if (odd.size()<1){
        no;
        return;
    }

    if (n==3){
        if (odd.size()==0)
            no;
        else if (odd.size()==2)
            no;
        else if (odd.size()==3){
            yes;
            cout<<odd[0]+1<<' '<<odd[1]+1<<' '<<odd[2]+1<<nl;
        }
        else{
            yes;
            cout<<even[0]+1<<' '<<even[1]+1<<' '<<odd[0]+1<<nl;
        }
        return;
    }

    if (odd.size()>=3){
        yes;
        cout<<odd[0]+1<<' '<<odd[1]+1<<' '<<odd[2]+1<<nl;
        return;
    }
    else if (odd.size()>=1 && even.size()>=2){
        yes;
        cout<<odd[0]+1<<' '<<even[0]+1<<' '<<even[1]+1<<nl;
        return;
    }
    no;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n] ;
        for (int i=0; i<n; i++)
            cin>>arr[i] ;
        solve(n,arr) ;
    }
    return 0;
}