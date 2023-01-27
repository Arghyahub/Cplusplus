#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ll long long
using namespace std;

void solve(int n, int m, int *arr, int *crr){
    sort(crr,crr+m,greater<int>()) ;
    vector<int> frq(n+1,0) ;
    for (int i=0; i<n; i++)
        frq[arr[i]]++;
    
    priority_queue<int> pq;
    for (int i=1; i<=n; i++){
        if (frq[i]!=0)
            pq.push(frq[i]) ;
    }

    int ind=0 , ans=0;
    while (!pq.empty() && ind<m){
        int num = pq.top() ;
        pq.pop() ;

        if (num > crr[ind]){
            ans+=crr[ind] ;
            pq.push(num-crr[ind]) ;
        }
        else{
            ans+=num;
            // while (num<crr[ind] && !ms.empty()){
            //     num+=*ms.begin() ;
            //     ms.erase(ms.begin()) ;
            // }
        }
        ind++;
    }
    cout<<ans<<nl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n] ;
        int crr[m] ;
        for (int i=0; i<n; i++) cin>>arr[i] ;
        for (int i=0; i<m; i++) cin>>crr[i] ;
        solve(n,m,arr,crr) ;
    }
    return 0;
}