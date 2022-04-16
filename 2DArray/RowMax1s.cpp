#include<iostream>
using namespace std;
int main(){
    int N = 4 , M = 4 ;
    int Arr[][M] = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0} } ;
    
    // Top right corner swapping method
    int row=0, col=M-1 ,  res=-1 ;

    while (row<N && col>=0)
    {
        if (Arr[row][col]==1)
        {
            res=row ;
            col-- ;
        }
        else
        {
            row++ ;
        }
    }
    cout<<"Row Index with maxm 1 is : "<<res ;

    return 0 ;
}