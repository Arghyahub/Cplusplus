#include<iostream>
#include<bitset>
using namespace std;
int main(){
    
    int a , b , i,  n , ans ;

    /*
    Q1. CHECK IF A NUMBER IS ODD OR EVEN ?
    */
    a = 23 ;

    if (a&1)                        // THE LAST BIT SIGNIFIES IF A NUMBER IS ODD OR EVEN
        cout<<"Odd number"<<endl;
    else
        cout<<"Even Number"<<endl;

    cout<<endl;
    // Q2. CHECK IF i'TH BIT OF A NUMBER IS SET OR NOT

    b = 64 ;
    i = 2 ; // starts from 0 

    int mask = 1<<i ; // 1 --> 1<<2 = 100
    bool set = mask&b ;  // 0 if not set, 1 if set
    if (set)
        cout<<"Set bit"<<endl;
    else
        cout<<"Not set bit"<<endl;

    cout<<endl;


    /* Q3. CHANGE i'TH BIT TO ZERO
        EG : A = 10 : 1010
            i = 1
            ANS = 1000
    */
    a = 10 ;
    i = 1 ;

    int tempMask = 1<<i ;
    mask = ~tempMask ;

    cout<<"The number a="<<a<<" has binary : "<<bitset<8>(a)<<endl;
    cout<<"The number i="<<i<<" binary of mask is  : "<<bitset<8>(mask)<<endl;

    cout<<"After flip :"<<endl;
    ans = mask&a ;
    cout<<"Answer : "<<ans<<" binary is : "<<bitset<8>(ans)<<endl<<endl;


    /**
     * Q4. REVERSE the last set bit :
     * EG : 13 = 1101
     *      12 = 1100
     * 
     * 13&12   = 1100
     * 
     *  EG : 12 = 1100
     *       11 = 1011
     * 
     * 12&11    = 1000
     * 
     */
    a = 12 ;
    cout<<"For number : "<<a<<" Binary : "<<bitset<8>(a)<<endl; ;
    ans = a&(a-1) ;
    cout<<"Anser is : "<<ans<<" Binary : "<<bitset<8>(ans)<<endl<<endl ;

    /**
     * Q5. CHECK IF A NUMBER IS A POWER OF 2?
     * IF IT HAS ONE 1 IN ITS BINARY THEN IT'S A POWER OF TWO
     * 
     * EG:
     * N = 12 : 1100
     * N-1 = 11 : 1011
     * 
     * N&(N-1) != 0
     * .:. N IS NOT A POWER OF TWO
     * 
     * EG:
     * N  = 8 : 1000
     * N-1= 7 : 0111
     * 
     * N&(N-1) = 0
     * .:. N IS A POWER OF 2
     * 
     */

    a = 8 ;
    cout<<"For number : "<<a<<" Binary : "<<bitset<8>(a)<<endl; ;
    ans = a&(a-1) ;
    if (ans==0)
        cout<<"Number is a power of 2\n\n" ;
    else
        cout<<"Number is not a power of 2\n\n" ;
    

    //
    
    
    return 0 ;
}