#include<iostream>
using namespace std;
int expo(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    
    // find a^b/2 
    int ans=expo(a,b/2) ;

    // if b is even : op=a^b/2 * a^b/2
    if (b%2==0)
        return ans * ans ;
    
    // if b is odd : op=a * a^b/2 * a^b/2
    else
        return a*ans*ans ;
}
int main(){
    int a,b ;
    cin>>a>>b ;
    int ans=expo(a,b) ;
    cout<<ans ;

    return 0 ;
}