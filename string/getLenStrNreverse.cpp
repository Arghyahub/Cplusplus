#include<iostream>
using namespace std;
int main(){
    char arr[20] ;
    cout<<"Enter a string : ";
    gets(arr) ;

    int leng=0 , i = 0;
    for (int i=0; arr[i]!='\0'; i++)
        leng++ ;

    cout<<"Number of characters is : "<<leng<<endl ;

    // Reverse array
    int start=0, end=leng-1 ;

    while (start<end)
    {
        swap(arr[start],arr[end]) ;
        start++;
        end-- ;
    }

    cout<<"\nReverse of the name is : " ;
    for (int i=0; arr[i]!='\0'; i++)
        cout<<arr[i]<<" ";

    return 0 ;
}