#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n ;
    int **arr = new int*[n] ;
    // arr is a double pointer containing multiple pointers

    // now insert array in each pointer :
    
    for (int i=0; i<n; i++)
    {
        arr[i] = new int[n] ;// arr[0] = 1st pointer
    } // take the 1st pointer and insert the address of a array in heap

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>arr[i][j] ;
    }

    cout<<"\nArray is : " ;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<arr[i][j] ;
    }

    return 0 ;
}