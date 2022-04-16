#include<iostream>
#include<string>
using namespace std;

bool check(int arr[], int size)
{
    if (size==0 || size==1)
        return true ;
    
    if (arr[0]<arr[1])
        check(arr+1,size-1) ; // arr points to zero'th index so adding 1 will start array from next Index
    else
        return false ;
}
int main(){
    int n;
    cin>>n;
    int arr[n] ;
    for (int i=0; i<n; i++) cin>>arr[i] ;

    bool ans=check(arr,n) ;
    string str=(ans)?"True":"False" ;
    cout<<str ;

    return 0 ;
}