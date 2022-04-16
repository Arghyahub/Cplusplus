#include<iostream>
using namespace std;
int retSum(int arr[],int size)
{
    if (size==1)
        return arr[0] ;
    
    return arr[0] + retSum(arr+1,size-1) ;
}
int main(){
    int n;
    cin>>n;
    int arr[n] ;
    for (int i=0; i<n; i++) cin>>arr[i] ;

    int ans = retSum(arr,n) ;
    cout<<"\nSum is : "<<ans ;

    return 0 ;
}