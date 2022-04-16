#include<iostream>
using namespace std;

int firstoccurence(int arr[], int size, int key)
{
    int start=0 , end =size-1 ;
    int ans ;
    while (start<=end)
    {
        int mid = start + (end - start)/2 ;
        int element = arr[mid] ; 

        if (key == element)
        {
            ans=mid ;
            end = mid -1 ;
        }

        else if (key<element)
            end = mid - 1 ;
        else 
            start = mid + 1 ;
    }
    return ans ;
}

int lastoccurence(int arr[], int size, int key)
{
    int start=0 , end =size-1 ;
    int ans ;
    while (start<=end)
    {
        int mid = start + (end - start)/2 ;
        int element = arr[mid] ; 

        if (key == element)
        {
            ans=mid ;
            start = mid + 1 ;
        }

        else if (key<element)
            end = mid - 1 ;
        else 
            start = mid + 1 ;
    }
    return ans ;
}




int main(){
    int arr[10]={1,2,3,5,5,5,6,7,9,10} ;
    int n;
    cout<<"Enter a value :";
    cin>>n ;

    cout<<"\nThe first occurence of "<<n<<" is : "<<firstoccurence(arr,10,n) ;   

    cout<<"\nThe Last occurence of "<<n<<" is : "<<lastoccurence(arr,10,n) ; 

    return 0 ;
}