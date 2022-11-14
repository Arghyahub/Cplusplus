#include<iostream>
using namespace std;

int partition(int arr[], int l , int h)
{
    int data = arr[h] ;
    int i=l-1 ;

    for (int j=l; j<=h-1; j++)
    {
        if (arr[j] <= data)
        {
            i++ ;
            swap(arr[i],arr[j]) ;
        }
    }
    swap(arr[i+1],arr[h]) ;

    return i+1 ;
}

void quicksort(int arr[], int l , int h)
{
    if (l<h)
    {
        int pos = partition(arr,l,h) ;
                                        // ELEMENT AT POS IS ALREADY IN THE CORRECT POSITION
        quicksort(arr,l,pos-1) ;    // SKIP
        quicksort(arr,pos+1,h) ;    // IT
    }
}

int main(){
    int arr[] = {4,1,7,3,8,2,9,6} ;
    int n = sizeof(arr)/sizeof(int) ;

    cout<<"Array before Sort : ";
    for (int i=0; i<n; i++) cout<<arr[i]<<" " ;
    cout<<"\n" ;
    quicksort(arr,0,n-1) ;

    cout<<"Array after Sort : " ;
    for (int i=0; i<n; i++) cout<<arr[i]<<" " ;
    cout<<"\n";

    return 0 ;
}