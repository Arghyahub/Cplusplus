#include<iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50,60,70} ;
    int n = sizeof(arr)/sizeof(int) ;


    for (int i=0; i<n/2; i++)
    {
        swap(arr[i],arr[n-1-i]) ;
    }

    cout<<"printing the Array :"<<endl ;

    for (int i=0; i<n; i++) {cout<<arr[i]<<" " ;}

    // start and end method

    int start=0 , end=n-1 ;
    while (start<=end)
    {
        swap(arr[start],arr[end]) ;
        start++ ;
        end-- ;
    }

    cout<<"\nPrinting after reversing again :"<<endl ;
    for (int i=0; i<n; i++) {cout<<arr[i]<<" " ;}



    return 0 ;
}