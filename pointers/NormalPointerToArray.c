#include <stdio.h>
int main()
{
    int arr[4][2]={{10,20},{30,40},{50,60},{70,80}} ;
    int (*p)[2];        
    p=arr;
    int *q=(int *)arr;

    printf(("(*p)[2]        ,   *q")) ;
    printf(("\n %d       ,  %d"),p,q) ;
    p++;
    q++;
    printf(("\nAfter p++ q++")) ;
    printf(("\n %d       ,  %d"),p,q) ;
    /* as q is a int pointer after incementing it moves 4 bytes
    but p is a Array pointer so after incrementing it moves to the address of next columns 1st element
*/
    return 0;
}