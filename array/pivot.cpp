#include<iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int arr[]={7,9,1,2} ;
    int start=0, end=3 ;

    while (start<=end)
    {
        int mid = start + (end - start)/2 ;
        if (arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
            cout<<"\nIndex of pivot element is :"<<mid ;
            break;
        }

        else if (arr[mid]<arr[mid+1])
            end=mid - 1 ;
        else if (arr[mid]>arr[mid-1])
            start=mid +1 ;
    }
    return 0 ;
}