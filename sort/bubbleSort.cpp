#include<iostream>
using namespace std;
int main(){
    int arr[]={1,5,8,9,4,2,6} ;
    int n =sizeof(arr)/sizeof(int) ;

    for (int i=0; i<n-1; i++)
    {
        bool check = true ;
        for (int j=0; j<n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]) ;
                check = false ;
            }
        }
        if (check)
            break ;
    }

    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0 ;
}