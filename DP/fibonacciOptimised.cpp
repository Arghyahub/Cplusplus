#include<bits/stdc++.h>
using namespace std;

int main()        // SC O(1)    TC O(N)
{
    int n;
    cin>>n;
    
    int f = 0 ;
    int s = 1 ;
    for (int i=2; i<=n; i++){
        int c = f + s;
        f = s ;
        s = c ;
    }
    cout<<s<<endl;
    return 0 ;
}