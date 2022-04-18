#include <stdio.h>
int main()
{
    int *intpointer;
    float b=10.623;
    intpointer=(int *)&b;
    printf("\naddress of b : %u",&b);
    printf("\naddress of b as in intpointer : %u",intpointer);
    printf("\nvlaue of b as float : %f",b);
    printf("\nvlaue of b as int by %d:",b);
    int j=b;
    printf("\nvlaue of b as int by storing in int integer: %d\n",j);

    printf("\nvlaue of b as float in intpointer : %f",*intpointer);
    printf("\nvlaue of b as int in intpointer : %d",*intpointer);
    

    return 0;
}