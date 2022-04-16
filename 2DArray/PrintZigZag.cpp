#include<iostream>
using namespace std;
/*
 ⁰  ¹  ² <- index
1⬇ 2⬆ 3⬇
4⬇ 5⬆ 6⬇
7⬇ 8⬆ 9⬇
print this as 1 4 7 8 5 2 3 6 9*/
int main(){
    // for even column number we are going down
    // for odd column number we are going up

    int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} } ;
    int lastcol=sizeof(arr[0])/sizeof(int) -1 ; // Numbers of element is any array is equal to colmno.
    int lastrow=sizeof(arr)/sizeof(arr[0]) -1 ; // volume =m*n so total volume/numberof col = number of rows ;

    for (int col=0; col<=lastcol; col++)
    {
        if (col%2==0) // Even case
        {
            for (int row=0; row<=lastrow; row++)
            {
                cout<<arr[row][col]<<" " ;
            }
        }
        else        // Odd case
        {
            for (int row=lastrow; row>=0; row--)
            {
                cout<<arr[row][col]<<" " ;
            }
        }
    }    

    return 0 ;
}