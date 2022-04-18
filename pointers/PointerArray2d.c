#include <stdio.h>
int main()
{
    int arr[3][3]={{10,20,30},{40,50,60},{70,80,90}};

    // printf("\narr direct print : %u",arr);
    // printf("\narr 0th item address print : %u",&(arr[0]));

    /*
    1d array --> arr act as a pointer     --> value = *arr
    2d array --> arr act as a pointer of a pointer  --> value= **arr
    */

    printf("\n element : %d",*(arr+2) );
    printf("\n ekement : %d",*(*(arr+2) + 1 ) );
    
    return 0;
}