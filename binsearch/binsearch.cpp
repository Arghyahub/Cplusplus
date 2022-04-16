#include<iostream>
using namespace std;

int binsearch(int *ptr, int size, int num )
{
    int start = 0, end = size-1 ;

    while (start<=end)
    {
        int mid = (start + end)/2 ;
        int element = ptr[mid] ;

        if (element== num)
            return mid ;
        
        if (num<element)
            end=mid - 1 ;
        
        if (num>element)
            start = mid + 1 ;
    }
    return -1 ;
}

int main(){
    int arr[10]={1,4,6,9,12,34,47,59,77,99} ;
    cout<<"Enter a number to be found :" ;
    int  n;
    cin>>n;

    cout<<"Index of element "<<n<<" : "<<binsearch(arr, 10 , n) ;

    return 0 ;
}