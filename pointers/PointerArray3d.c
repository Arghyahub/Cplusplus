#include <stdio.h>
int main()
{
    int a[2][3][2]={
        {
            {2,4},
            {7,8},
            {3,4}
        },
        {
            {2,2},
            {2,3},
            {3,4}
        }
    };

    printf("\na is : %u",a) ;
    printf("\n*a is : %u",*a) ;
    printf("\n**a is : %u",**a) ;
    printf("\n***a is : %u",***a) ;
    printf("\na+1 is : %u",a + 1) ;
    printf("\n*a+1 is : %u",*a + 1) ;
    printf("\n**a+1 is : %u",**a+1) ;
    printf("\n***a+1 is : %u",***a+1) ;
    return 0;
}