#include<iostream>
using namespace std;
void selsort(int *arr,int i,int n)
{
    if (i==n-1)
        return ;
    int minIndex=i ;
    for (int j=i+1; j<n; j++)
    {
        if (arr[j]<arr[minIndex])
            minIndex= j ;
    }
    swap(arr[i],arr[minIndex]) ;
    selsort(arr,i+1,n) ;
}
int main(){
    int n;
    cin>>n ;
    int arr[n] ;
    for (int i=0; i<n; i++) cin>>arr[i] ;

    selsort(arr,0,n) ;

    for (int i=0; i<n; i++) cout<<arr[i]<<" " ;

    return 0 ;
}