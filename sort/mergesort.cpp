#include<iostream>
using namespace std;
int main(){
    int arr1[5] = {1,3,5,7,9} ;
    int arr2[3] = {2,4,6} ;
    int arr3[8] = {0} ;
    int l=5, m=3, n=8 ;

    int i=0, j=0, k=0 ;

    while (i<5 && j<3)
    {
        if (arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i] ;
            k++ ;
            i++ ;
        }
        else
        {
            arr3[k]=arr2[j] ;
            k++ ;
            j++ ;
        }
    }

    while (i<5)
    {
        arr3[k]=arr1[i];
        k++;
        i++;
    }

    while (j<3)
    {
        arr3[k]=arr2[j];
        k++;
        j++;
    }

    for (int i=0; i<8; i++) {cout<<arr3[i]<<" " ; }


    return 0 ;
}