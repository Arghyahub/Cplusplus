#include<iostream>
using namespace std;
// O(log(a+b))
int gcd(int a,int b) // a = b*c +r          --> [1]
{                       // b = rc + r2      --> [2]
    if (b==0)           // we can also right as
        return a ;      //  a  = b*c + a%b    --> [1`]
    else                //  b  = rc  + b%r
        return gcd(b,a%b) ; // .:. a-> b , b->r or r==a%b 
}
int main(){
    int a,b ;
    cin>>a;
    cin>>b ;
    if (b>a)
        swap(a,b) ;
    int ans=gcd(a,b) ;
    cout<<"Gcd is : "<<ans ;
    return 0 ;
}