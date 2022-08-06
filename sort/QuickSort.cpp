#include<iostream>
using namespace std;
int partition(int *arr, int s , int e)
{
    // Put the first Element of start in right position (pivot betn high and low)
    int pivot = arr[s] ;
    int count=0 ;
    for (int i=s+1; i<=e; i++)
    {
        if (arr[i]<=pivot)  // even if it's equal send it to the right Index
            count++ ;
    }
    
    int PivotIndex=s+count ;
    swap(arr[s],arr[PivotIndex]) ;
    int i=s , j=e ;
    while (i<PivotIndex && j>PivotIndex)  // move upto the Pivot , not the entire array
    {
        while (arr[i]<pivot)
            i++ ;
        while (arr[j]>pivot)
            j-- ;
        if (arr[i]>pivot && arr[j]<pivot)
        {
            swap(arr[i],arr[j]) ;
            i++ ;
            j-- ;
        }
    }
    return PivotIndex ;

}

void quickSort(int *arr,int s, int e)
{
    if (s>=e)
        return ;
    
    // find the partition Index 
    int PartIndex=partition(arr,s,e) ;

    // sort left of partition Index
    quickSort(arr,s,PartIndex-1) ;

    // Sort Right of Partition Index
    quickSort(arr,PartIndex+1,e) ;
}
int main(){
    int arr[]={1,9,3,7,2,8} ;
    int n =6 ;

    quickSort(arr,0,n-1) ;

    for (int i=0; i<n ;i++) cout<<arr[i]<<" " ;

    return 0 ;
}