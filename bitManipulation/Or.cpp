#include<iostream>
#include<bitset>
using namespace std;
int main(){
    int a , b , i , n , ans, mask ;
    
    // Q1. SET i'TH BIT

    a = 56 ;
    cout<<"Binary of a : "<< bitset<8>(a) <<endl; ;
    i = 2 ;
    mask = 1<<1 ;

    ans = a|mask ;
    cout<<"Binary of new a : "<<bitset<8>(ans)<<" Value : "<<ans<<endl;

    return 0 ;
}