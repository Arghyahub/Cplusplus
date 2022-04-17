#include<iostream>
using namespace std;
void insort(int *arr,int i,int n)
{
    if (i>=n)
        return ;
    
    int j=i-1 ;
    int temp = arr[i] ;
    while (j>=0 && arr[j]>temp)
    {
        arr[j+1]=arr[j] ;
        j-- ;
    }
    arr[j+1]=temp ;

    insort(arr,i+1,n) ;
}
int main(){
    int n;
    cin>>n;
    int arr[n] ;
    for (int i=0; i<n; i++) cin>>arr[i] ;

    insort(arr,1,n) ;

    for (int i=0; i<n; i++) cout<<arr[i]<<" " ;
    return 0 ;
}