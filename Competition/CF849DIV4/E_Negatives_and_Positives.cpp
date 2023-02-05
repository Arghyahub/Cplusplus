#include<bits/stdc++.h>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n] ;
        ll sum=0, neg=0, x;
        for (int i=0; i<n; i++){
            cin>>x ;
            arr[i] = abs(x) ;
            sum+=arr[i] ;
            if (x<0)
                neg++;
        }

        sort(arr,arr+n) ;

        sum+= (neg&1)? -2*arr[0]:0;
        cout<<sum<<nl;
    }
    return 0;
}