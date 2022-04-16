#include<iostream>
using namespace std;
int binSearch(int *arr,int s, int e, int key)
{
    int mid = s+(e-s)/2 ;
    if (s>e)
        return -1 ;
    if (arr[mid]==key)
        return mid ;
    else if (arr[mid]>key)
        return binSearch(arr,s,mid-1,key) ;
    else
        return binSearch(arr,mid+1,e,key) ;
}
int main(){
    int arr[]={1,5,7,10,24,51,70,88} ;
    int key , ans , n=sizeof(arr)/sizeof(int) ; 
    cin>>key ;
    
    ans=binSearch(arr,0,n-1,key) ;
    cout<<"Index of Element : "<< ans ;

    return 0 ;
}