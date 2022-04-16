#include<iostream>
#include<vector>
using namespace std;
// find all prime number between 1 to n
int main(){
    int n=10 ;
    vector<bool> v(n+1,true) ;
    int count =0 ;
    v[0]=v[1]=false ;   // set 0 and 1 equals false
    for (int i=2; i<n; i++)
    {
        if (v[i])  //if v[i] is true ie, its prime
        {
            count++ ; // increment count
            for (int j=2*i; j<n; j=j+i) // make all the numbers divisible by v[i]= false ;
                v[j]=0 ;
        }
    }
    cout<<count ;
    return 0 ;
}