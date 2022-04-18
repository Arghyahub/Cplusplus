#include <stdio.h>
int main()
{
    int *IntegerPointer;
    float f =10.323 ;
    
    IntegerPointer = &f;

    printf("%f",*IntegerPointer) ;
    return 0;
}