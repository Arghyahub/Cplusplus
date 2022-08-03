#include<iostream>
using namespace std;
int main(){
    char *ch = new char ; // a memory block is allocated in heap
    // whose address is stored in char

    // the char in heap will take 1 byte
    // pointer takes 8 byte

    int* arr= new int[5] ;
    for (int i=0; i<5; i++)
        arr[i]=i ;
    
    for (int i=0; i<5; i++) cout<<arr[i]<<" " ;
    delete []arr ;

    return 0 ;
}