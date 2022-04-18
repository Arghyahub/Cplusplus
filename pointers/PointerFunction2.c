#include <stdio.h>
int main()
{
    /*incrementing pointer and understanding*/
    int i=10;
    int *p;
    p=&i;

    int *k;
    k=p+1;

    printf("\nValue of i : %d",i);
    printf("\nAddress of i : %u",p);
    printf("\nAddress at &i+1 \n: %u",k); // we see a difference of 4 
    /*size of int is 4 so when we increment the value of a pointer then we simply shift the pointer to 
    the size of data type*/
    return 0;
}