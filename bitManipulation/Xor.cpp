#include<iostream>
using namespace std;
int main(){
    int a = 2 ;
    int ans =a^a ;
    cout<<"XOR OF A^A = "<< a <<endl<<endl;

    // BASICALLY XOR CANCELS SAME ELEMENTS

    // Q1. FIND AN ELEMENT WITH OCCURRENCE = 1 , other elements occur even number of times

    int arr[] = { 1,4,2,6,7,2,4,1,6 } ;

    int XOR = 0 ;
    for (auto x : arr)
        XOR = XOR^x ;

    cout<<"UNIQUE NUM : "<<XOR<<endl<<endl;


    // Q2. SWAP TWO NUMBERS WITHOUT USING THIRD VARIABLE
    a = 5 ;
    int b = 8 ;
    cout<<"Before swap : a = "<<a<<" b = "<<b<<endl;

    a = a^b ; // a^b
    b = a^b ; // a^b^b = a
    a = a^b ; // a^b^a = b

    cout<<"After swap : a = "<<a<<" b = "<<b<<endl<<endl;


    // Q3. GIVEN NUMBER N, FIND THE XOR OF ALL NATURAL NUMBERS UPTO N WILL BE EQUAL TO
    /**
     * NOOB :
     * for (int i=1; i<n; i++)
     *      ans = ans^i;
     *  ==> O(n) solution
     */
    // FOR MULTIPLE OF 4 WE ARE GETTING N AS OUTPUT : 1^2^3^...^(4n) = 4n
    // a=4n
    // FOR N%4==1 : 1
    // FOR N%4==2 : a+1
    // FOR N%4==3 : 0
    cout<<"Enter number to get XOR of all natural numbers upto : ";
    cin>>a ;
    switch (a%4)
    {
        case 0 :
            cout<<a;
            break;
        case 1 :
            cout<<1 ;
            break;
        case 2 :
            cout<<a+1 ;
            break;
        case 3 :
            cout<<0;
            break;
        cout<<endl<<endl;            
    }


    /* Q2. XOR OF [L,R] = ?
        XOR(R) ^ XOR(L-1)
        BECAUSE :
        EG : XOR ( [3,6] )
        XOR(6) = 1^2^3^4^5^6
        XOR(2) = 1^2
        
        XOR(6)^XOR(2) = 3^4^5^6 ✔
    */



    return 0 ;
}