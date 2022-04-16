#include<iostream>
using namespace std;
int main(){
    int arr[]={1,4,2,7,3,9} ;
    int size = sizeof(arr)/sizeof(int) ;

    for (int i=0; i<size; i++)
    {
        int minIndex=i ;
        for (int j=i+1; j<size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex=j ;
        }
        swap(arr[i],arr[minIndex]) ;
    }

    for (int i=0; i<size; i++)
    {
        cout<<" "<<arr[i];
    }

    return 0 ;
}