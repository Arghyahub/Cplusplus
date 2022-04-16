#include<iostream>
#include<vector>
using namespace std;
// k will be given shift elements to their succesive kth element
int main(){
    vector<int> arr = {1,2,3,4,5,6} ;
    vector<int> ans = {0} ;
    int n= arr.size() , k=2;

    for (int i=0; i<n; i++)
    {
        ans[ (i+k)%n ] = arr[i] ; // lets explain circular array
    }

    /*
    %n gives us output from 0 to n-1
    say for x<10 : x=9 so x%10 = 9
    say x>10 : x=12 so x%10 = 2
    */

    for (int k=0; k<n; k++) { cout<<ans[k]<<" " ; }

    return 0 ;
}