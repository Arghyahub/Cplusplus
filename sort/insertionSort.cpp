#include<iostream>
using namespace std;
int main(){
    int arr[]= {1,7,3,9,4,10} ;
    int size = sizeof(arr)/sizeof(int) ;

    for (int i=0; i<size; i++)
    {
        int temp = arr[i] ;
        int j=i-1 ;

        while ( j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j] ;
            j-- ;
        }
        arr[j+1]=temp ;
    }

    for (int i=0; i<size; i++) {cout<<arr[i]<<" " ;}

    return 0 ;
}