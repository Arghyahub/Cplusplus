#include<iostream>
using namespace std;
int main(){
    char arr[20] ;
    // Input type 1
    // cout<<"\nEnter your full name : ";  // -> can store one word at a time but creates a buffer problem too
    // cin>>arr ;
    // cout<<"Your full name is : "<<arr<<endl ;

    // Input type 2
    cout<<"\nEnter your full name : ";
    gets(arr) ;                                   // best
    cout<<"Your full name is(gets) : "<<arr<<endl ;

    // Input type 3
    cout<<"\nEnter your full name : ";
    scanf("%s",arr) ;                              // can take one word at a time but creates a buffer problem
    cout<<"Your full name is(scanf) : "<<arr<<endl ;

    return 0 ;
}