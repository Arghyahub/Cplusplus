#include<iostream>
using namespace std;
int main(){
    int a,b , res=1 ;
    cin>>a ;
    cin>>b ;
    for (int i=1; i<=min(a,b); i++)
    {
        if (a%i==0 && b%i==0 )       // greatest number that divides a & b 
            res=i ;
    }
    cout<<"Gcd is : "<<res ;
    return 0 ;
}