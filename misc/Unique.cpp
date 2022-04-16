/* Given an array has one unique element and other elements are in pair
eg : {1,2,3,3,2,1,5}
Find the unique number*/

#include<iostream>
using namespace std;
int main(){
    int arr[9]={1,1,3,3,5,6,6,9,9} ;

     /* Xor cancells similar elements
     0 ^ 0 = 1
     1 ^ 1 = 0
     a ^ a = a
     */

    int ans=0;
    for (int i=0; i<9; i++)
        ans=ans^arr[i] ;

    cout<<ans;
    return 0 ;
}