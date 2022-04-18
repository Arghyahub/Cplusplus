#include <stdio.h>
int main()
{
    int arr[4][2]={{10,20},{30,40},{50,60},{70,80}} ;
    int (*p)[2];        // Number of colums is to be mentioned
    p=arr;

    printf("%d",*(*(p+2)+1)) ;
    return 0;
}