#include<iostream>
using namespace std;
// gcd * lcm = a*b
int gcd(int a, int b)
{
    if (b==0)
        return a ;
    else
        return gcd(b,a%b) ;
}
int main(){
    int a, b ;
    cin>>a>>b ;
    if (b>a)
        swap(a,b) ;
    int gcf=gcd(a,b) ;
    int lcm=(a*b)/ gcf ;
    cout<<"Lcm of a & b is : "<<lcm ;
    return 0 ;
}